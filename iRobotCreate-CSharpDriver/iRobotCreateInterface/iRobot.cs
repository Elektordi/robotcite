// iRobot.cs created with MonoDevelop
// User: elektordi at 23:13 11/09/2008
//
//

using System;
using System.IO.Ports;
using System.Threading;

namespace iRobotCreateInterface
{
    public delegate void IrDataEventHandler(object sender, IrDataEventArgs e);

    public class iRobot
    {
        public event IrDataEventHandler IrData;
        
        public iRobotSensors sensors;
        public int Distance=0, Angle=0;
        
        protected SerialPort io;
        protected byte LedBits=0, PowerColor = 255, PowerIntensity = 255;
        protected byte DigitalOutBits = 0;
        protected byte[] pwm = new byte[3];
        protected Thread ReadThread;
        
        private string port;
        private bool ignore_errors = false;
        private byte CheckSum, BytesToRead = 0;
        
        public iRobot(string SerialPort, bool IgnoreCommErrors)
        {
            ignore_errors = IgnoreCommErrors;
            port = SerialPort;
            Reconnect();
        }
        
        public iRobot(string SerialPort)
        {
            port = SerialPort;
            Reconnect();
        }
        
        public void Reconnect()
        {
            sensors.LastUpdate = DateTime.MinValue;
            
            if (io != null)
    			if (io.IsOpen)
    				io.Close();

            io = new SerialPort(port, 57600); // UNDONE: Autodétection de port
    		io.Open();
		    io.ReadTimeout = 4000;
            
            if (ReadThread != null)
    			if (ReadThread.ThreadState == ThreadState.Running)
    				ReadThread.Abort();
            
            SendByte(128); // IO Init
            Thread.Sleep(30); // Waiting for iRobot to start...

            if(io.BytesToRead>0) io.DiscardInBuffer();
            // Demande d'un stream avec les capteurs de 7 à 34
            SendByte(148);
            SendByte(2);
            SendByte(0);
            SendByte(4);
            
            ThreadStart job = new ThreadStart(ReadThreadHandler);
            ReadThread = new Thread(job);
            ReadThread.Start();

        }
        
        public void Disconnect() // TODO: A lier au destructeur de la classe
        {
            if (ReadThread != null)
    			if (ReadThread.ThreadState == ThreadState.Running)
    				ReadThread.Abort();
            
            if (io != null)
    			if (io.IsOpen)
    				io.Close();
        }
        
        private void ReadThreadHandler()
        {
            while(io.IsOpen)
            {
                // On recoit normalement les données toutes les 15ms
                while(io.BytesToRead<55) // 55 = Init + N + 52 + Checksum
                    Thread.Sleep(5);
                
                if(ReadByte()!=19) continue; // On se cale sur l'octet de début de flux
                if(ReadByte()!=52) {CommError("Mauvaise en-tête du flux de données."); continue;};
                
                // FIXME: Vérifier les valeurs !!!
                BytesToRead = 52+1;
                CheckSum = 52;
                iRobotSensors s = new iRobotSensors();
                
                while(BytesToRead>1)
                {
                    byte id = ReadByte();
                    switch(id)
                    {
                        case 7:
                            byte Drops = ReadByte();
                            s.WheeldropCaster = ExtractBit(4,Drops);
                            s.WheeldropLeft = ExtractBit(3,Drops);
                            s.WheeldropRight = ExtractBit(2,Drops);
                            s.BumpLeft = ExtractBit(1,Drops);
                            s.BumpRight = ExtractBit(0,Drops);
                            break;
                        case 8:
                            s.Wall = ReadByte()==1;
                            break;
                        case 9:
                            s.CliffLeft = ReadByte()==1;
                            break;
                        case 10:
                            s.CliffFrontLeft = ReadByte()==1;
                            break;
                        case 11:
                            s.CliffFrontRight = ReadByte()==1;
                            break;
                        case 12:
                            s.CliffRight = ReadByte()==1;
                            break;
                        case 13:
                            s.VirtualWall = ReadByte()==1;
                            break;
                        case 14:
                            byte Overcurrent = ReadByte();
                            s.OvercurrentLeftWheel = ExtractBit(4,Overcurrent);
                            s.OvercurrentRightWheel = ExtractBit(3,Overcurrent);
                            s.OvercurrentLD2 = ExtractBit(2,Overcurrent);
                            s.OvercurrentLD1 = ExtractBit(1,Overcurrent);
                            s.OvercurrentLD0 = ExtractBit(0,Overcurrent);
                            break;
                        case 15:
                        case 16:
                            ReadByte(); // Unused (=0)
                            break;
                        case 17:
                            s.Infrared = ReadByte();
                            break;
                        case 18:
                            byte Buttons = ReadByte();
                            s.ButtonAdvance = ExtractBit(2,Buttons);
                            s.ButtonPlay = ExtractBit(0,Buttons);
                            break;
                        case 19:
                            s.Distance = ReadInt16();
                            break;
                        case 20:
                            s.Angle = ReadInt16();
                            break;
                        case 21:
                            s.ChargingState = (iRobotChargingState)ReadByte();
                            break;
                        case 22:
                            s.Voltage = ReadUint16();
                            break;
                        case 23:
                            s.Current = ReadInt16();
                            break;
                        case 24:
                            s.BatteryTemp = ReadInt16();
                            break;
                        case 25:
                            s.BatteryCharge = ReadUint16();
                            break;
                        case 26:
                            s.BatteryCapacity = ReadUint16();
                            break;
                        case 27:
                            s.WallSignal = ReadUint16();
                            break;
                        case 28:
                            s.CliffLeftSignal = ReadUint16();
                            break;
                        case 29:
                            s.CliffFrontLeftSignal = ReadUint16();
                            break;
                        case 30:
                            s.CliffFrontRightSignal = ReadUint16();
                            break;
                        case 31:
                            s.CliffRightSignal = ReadUint16();
                            break;
                        case 32:
                            byte DigitalInputs = ReadByte();
                            s.DigitalInput_DeviceDetect = ExtractBit(4,DigitalInputs);
                            s.DigitalInput_3 = ExtractBit(3,DigitalInputs);
                            s.DigitalInput_2 = ExtractBit(2,DigitalInputs);
                            s.DigitalInput_1 = ExtractBit(1,DigitalInputs);
                            s.DigitalInput_0 = ExtractBit(0,DigitalInputs);
                            break;
                        case 33:
                            s.AnalogInput = ReadUint16();
                            break;
                        case 34:
                            byte Charging = ReadByte();
                            s.ChargingAvailable_HomeBase = ExtractBit(1,Charging);
                            s.ChargingAvailable_InternalCharger = ExtractBit(0,Charging);
                            break;
                        case 35:
                            s.Mode = (iRobotMode)ReadByte();
                            break;
                        case 36:
                        case 37:
                        case 38:
                            ReadByte(); // Useless!!!
                            break;
                        case 39:
                        case 40:
                        case 41:
                        case 42:
                            ReadByte(); // Use...
                            ReadByte(); // ...less!
                            break;
                    }
                }
                if(BytesToRead!=0)  {BytesToRead=0; CommError("Mauvaise longeur du flux de données."); continue;};
                if(CheckSum+ReadByte()!=0) {CommError("Flux de données endommagé."); continue;};
                s.LastUpdate = DateTime.Now;
                sensors = s;
                
                Distance += s.Distance;
                Angle += s.Angle;
                if(s.Infrared<255)
                {
                    IrDataEventArgs e = new IrDataEventArgs(s.Infrared);
                    IrData(this, e);
                }
            }
            
        }
        
        protected void CommError(string error)
        {
            Console.WriteLine("[iRobot Comm Error] "+error);
            if(ignore_errors) return;
            throw new iRobotException(error);
        }
                
        protected byte ReadByte()
        {
            if (io == null) {CommError("Le port série n'est pas initialisé."); return 0; }
    		if (!io.IsOpen) {CommError("Le port série n'est pas ouvert."); return 0; }
                   
            byte data = (byte)io.ReadByte();            
            
            if(BytesToRead>0)
            {
                BytesToRead--;
                CheckSum += data;
            }
            
            return data;
        }
        protected Int16 ReadInt16()
        {
            return (Int16)(ReadUint16()-Int16.MaxValue);
        }
        protected UInt16 ReadUint16()
        {
            return (UInt16)((ReadByte()<<8)+ReadByte());
        }
        protected bool ExtractBit(int n, byte b)
        {
            return ((b >> n)&1)==1;
        }
        
        protected void SendByte(byte b)
        {
            if (io == null) {CommError("Le port série n'est pas initialisé."); return; }
    		if (!io.IsOpen) {CommError("Le port série n'est pas ouvert."); return; }
                
            io.BaseStream.WriteByte(b);
        }
        protected void SendInt16(Int16 i)
        {
            SendUint16((UInt16)(i+Int16.MaxValue));
        }
        protected void SendUint16(UInt16 i)
        {
            io.BaseStream.WriteByte((byte) ((i >> 8) & 0xFF));
            io.BaseStream.WriteByte((byte) (i & 0xFF));
        }
        
        public void Start(iRobotMode mode)
        {
            if(mode == iRobotMode.Passive)
            {
                SendByte(128);
                return;
            }
            if(mode == iRobotMode.Safe)
            {
                SendByte(131);
                return;
            }
            if(mode == iRobotMode.Full)
            {
                SendByte(132);
                return;
            }
        }
        
        public void Demo(iRobotDemo demo)
        {
            SendByte(136);
            SendByte((byte)demo);
        }
        
        public void Stop()
        {
            DriveDirect(0,0);
        }
        
        public void Drive(Int16 velocity, Int16 radius)
        {
            SendByte(145);
            SendInt16(velocity);
            SendInt16(radius); 
        }
        
        public void DriveDirect(Int16 right, Int16 left)
        {
            SendByte(145);
            SendInt16(right);
            SendInt16(left);
        }
        
        public void LedPlay(bool on)
        {
            if(on) LedBits = (byte)( LedBits | 1 );
            else LedBits = (byte)( LedBits & (255-1) );
            UpdateLeds();
        }
        
        public void LedAdvance(bool on)
        {
            if(on) LedBits = (byte)( LedBits | 3 );
            else LedBits = (byte)( LedBits & (255-3) );
            UpdateLeds();
        }
        
        public void LedPower(byte intensity)
        {
            PowerIntensity = intensity;
            UpdateLeds();
        }
        
        public void LedPower(byte intensity, byte color)
        {
            PowerColor = color;
            PowerIntensity = intensity;
            UpdateLeds();
        }
        
        protected void UpdateLeds()
        {
            SendByte(139);
            SendByte(LedBits);
            SendByte(PowerColor);
            SendByte(PowerIntensity);
        }
        
        public void DigitalOut(byte num, bool state)
        {
            if(num>2 || num<0) throw new InvalidOperationException("Invalid Digital Output ID ("+num.ToString()+")");
            if(state) DigitalOutBits = (byte)( DigitalOutBits | num );
            else DigitalOutBits = (byte)( DigitalOutBits & (255-num) );            
            
            SendByte(147);
            SendByte(DigitalOutBits);
        }
        
        public void PWM(byte num, byte dutycycle)
        {
            if(num>2 || num<0) throw new InvalidOperationException("Invalid PWM ID ("+num.ToString()+")");
            pwm[num] = (byte)(dutycycle/2);
            
            SendByte(144);
            SendByte(pwm[2]);
            SendByte(pwm[1]);
            SendByte(pwm[0]);
        }
        
        public void SendIR(byte data)
        {
            SendByte(151);
            SendByte(data);
        }
        
        public void Forward(Int16 distance_in_mm)
        {
            Forward(distance_in_mm, Int16.MaxValue);
        }
        public void Forward(Int16 distance_in_mm, Int16 speed)
        {
            Distance = 0;
            Drive(speed, Int16.MaxValue/2);
            while(Distance<distance_in_mm) Thread.Sleep(15);
            Stop();
        }
        
        public void Backward(Int16 distance_in_mm)
        {
            Forward(distance_in_mm, Int16.MinValue);
        }
        public void Backward(Int16 distance_in_mm, Int16 speed)
        {
            Forward(distance_in_mm, (Int16)(-speed));
        }
        
        public void TurnLeft(Int16 angle_in_degree) // Sur place...
        {
            TurnLeft(angle_in_degree, Int16.MinValue, Int16.MaxValue);
        }
        public void TurnLeft(Int16 angle_in_degree, Int16 radius)
        {
            TurnLeft(angle_in_degree, radius, Int16.MaxValue);
        }
        public void TurnLeft(Int16 angle_in_degree, Int16 radius, Int16 speed)
        {
            Angle = 0;
            Drive(speed, radius);
            while(-Angle<angle_in_degree) Thread.Sleep(15);
            Stop();
        }
        
        public void TurnRight(Int16 angle_in_degree)  // Sur place...
        {
            TurnRight(angle_in_degree, Int16.MaxValue, Int16.MaxValue);
        }
        public void TurnRight(Int16 angle_in_degree, Int16 radius)
        {
            TurnRight(angle_in_degree, radius, Int16.MaxValue);
        }
        public void TurnRight(Int16 angle_in_degree, Int16 radius, Int16 speed)
        {
            Angle = 0;
            Drive(speed, radius);
            while(Angle<angle_in_degree) Thread.Sleep(15);
            Stop();
        }
    }
}
