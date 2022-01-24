using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Ships
{
    class Program
    {
        static Semaphore
            cave = new Semaphore(5, 5),
            dock = new Semaphore(3, 3);    
        static void Main(string[] args)
        {
            for(int i = 0; i < 10; i++)
            {
                ShipAsync(i.ToString());
            }
            Thread.Sleep(100000);
        }

        
        static async void ShipAsync(string name)
        {
            Console.WriteLine($"{name} near the cave.");

            cave.WaitOne();
            Console.WriteLine($"{name} is going through the cave.");
            await Task.Delay(2000);
            cave.Release();

            Console.WriteLine($"{name} near the dock.");

            dock.WaitOne();
            Console.WriteLine($"{name} unload started.");
            await Task.Delay(2000);
            Console.WriteLine($"{name} unload finished.");
            dock.Release();

            cave.WaitOne();
            Console.WriteLine($"{name} is going through the cave backward.");
            await Task.Delay(2000);
            cave.Release();

            Console.WriteLine($"{name} went away.");
        }
    }
}
