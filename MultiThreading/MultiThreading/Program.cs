﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace MultiThreading
{
    class Program
    {

        static object locker = new object();

        static void Main(string[] args)
        {

            #region Threads
            //Thread thread = new Thread(new ParameterizedThreadStart(Printing));

            //thread.Start(-1);

            //for (int i = 0; i < 100; i++)
            //    (new Thread(new ParameterizedThreadStart(Printing))).Start(i);

            //thread.Join();
            //Console.WriteLine("---------------------------");
            #endregion

            #region Tasks
            //Task task = Task.Run(Printing);
            //for(int i = 0; i < 100; i++)
            //{
            //    Console.WriteLine($"{i} Main");
            //}
            #endregion

            
            var t = PrintingAsync(100, "Hi");

            for (int i = 0; i < 100; i++)
            {
                PrintingAsync(100, $"Hi {i}");
            }

            Console.WriteLine(t.Result);

            Print("aaa");

            Task.Run(() =>
            {
                Console.WriteLine("Start");
                Console.WriteLine("aaa");
            }).GetAwaiter().OnCompleted(() => Console.WriteLine("Finish"));
        }

        static async Task Print(string s)
        {
            Console.WriteLine("Start");
            await Task.Run(() => Console.WriteLine(s));
            Console.WriteLine("Finish");
        }

        static async Task<string> PrintingAsync(int N, string s)
        {
            var t = Task<string>.Run(() =>
            {
                string res = "";
                Monitor.Enter(locker);
                Mutex m = new Mutex();

                Semaphore ss = new Semaphore(0, 6);
                

                try
                {
                    for (int i = 0; i < N; i++)
                    {

                        Console.WriteLine(s);
                        res += s;
                    }
                }
                finally
                {
                    Monitor.Exit(locker);
                }
                return res;

            });
            await t;
            await Task.Delay(20000);
            return t.Result;
        }

        

    }
}
