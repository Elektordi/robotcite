// iRobotHelpers.cs created with MonoDevelop
// User: elektordi at 19:55 12/09/2008
//
//

using System;

namespace iRobotCreateInterface
{

    public enum iRobotMode
    {
        //OFF = 0,
        Passive = 1,
        Safe = 2,
        Full = 3
    }
    
    public enum iRobotDemo
    {
        ABORT = -1,
        Cover = 0,
        CoverAndDock,
        SpotCover,
        Mouse,
        Figure8,
        Wimp,
        Home,
        Tag,
        Pachelbel,
        Banjo
    }
    
    public enum iRobotChargingState
    {
        NotCharging = 0,
        Reconditioning,
        Full,
        Trickle,
        Waiting,
        Fault
    }
    
    public struct iRobotSensors
    {
        public DateTime LastUpdate;
        
        // ID 7
        public bool WheeldropCaster; // Bit 4
        public bool WheeldropLeft; // Bit 3
        public bool WheeldropRight; // Bit 2
        public bool BumpLeft; // Bit 1
        public bool BumpRight; // Bit 0
        // ID 8
        public bool Wall;
        // ID 9
        public bool CliffLeft;
        // ID 10
        public bool CliffFrontLeft;
        // ID 11
        public bool CliffFrontRight;
        // ID 12
        public bool CliffRight;
        // ID 13
        public bool VirtualWall;
        // ID 14
        public bool OvercurrentLeftWheel; // Bit 4
        public bool OvercurrentRightWheel; // Bit 3
        public bool OvercurrentLD2; // Bit 2
        public bool OvercurrentLD1; // Bit 1
        public bool OvercurrentLD0; // Bit 0
        // ID 15-16: UNUSED ?!
        // ID 17
        public byte Infrared;
        // ID 18
        public bool ButtonAdvance; // Bit 2
        public bool ButtonPlay; // Bit 0
        // ID 19
        public Int16 Distance;
        // ID 20
        public Int16 Angle;
        // ID 21
        public iRobotChargingState ChargingState;
        // ID 22
        public UInt16 Voltage;
        // ID 23
        public Int16 Current;
        // ID 24
        public int BatteryTemp;
        // ID 25
        public UInt16 BatteryCharge;
        // ID 26
        public UInt16 BatteryCapacity;
        // ID 27
        public UInt16 WallSignal;
        // ID 28
        public UInt16 CliffLeftSignal;
        // ID 29
        public UInt16 CliffFrontLeftSignal;
        // ID 30
        public UInt16 CliffFrontRightSignal;
        // ID 31
        public UInt16 CliffRightSignal;
        // ID 32
        public bool DigitalInput_DeviceDetect; // Bit 4
        public bool DigitalInput_3; // Bit 3
        public bool DigitalInput_2; // Bit 2
        public bool DigitalInput_1; // Bit 1
        public bool DigitalInput_0; // Bit 0
        // ID 33
        public UInt16 AnalogInput;
        // ID 34
        public bool ChargingAvailable_HomeBase; // Bit 1
        public bool ChargingAvailable_InternalCharger; // Bit 0
        // ID 35
        public iRobotMode Mode;
        // ID 36-42: Useless...
    }
    
    public class IrDataEventArgs : EventArgs
    {
        public readonly int IrByte;
        
        public IrDataEventArgs(byte data)
        {
            this.IrByte = data;
        }
    }
    
    public class iRobotException : Exception
    {
        public iRobotException(string msg) : base("[iRobot Exception] "+msg)
        {
        }
    }
   
}
