// Main.cs created with MonoDevelop
// User: elektordi at 23:29 10/09/2008
//
//
using System;
using iRobotCreateInterface;

namespace iRobotCreateTest
{
    class MainClass
    {
        static iRobot eve;        
        
        public static void Main(string[] args)
        {
            eve = new iRobot("/dev/ttyS0");            
            
            eve.Start(iRobotMode.Safe);
            while(true)
            {
                eve.Forward(500); // 50cm
                eve.TurnRight(90); // Angle droit
                eve.Forward(300);
                eve.TurnRight(90, 200);
                eve.Forward(100);
                eve.TurnRight(90, 200);
                eve.Forward(300);
                eve.TurnRight(90);
            }
            
        }
    }
}