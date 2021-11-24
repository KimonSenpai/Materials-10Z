using System;
using System.Text.RegularExpressions;

namespace ConsoleApp8
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "q9";
            Regex r = new Regex(@"[p-r]\d");
            Console.WriteLine(r.IsMatch(s));
            string str = "<aaa>bbb</aaa>";
            Regex r2 = new Regex(@"<(?<tag>.*?)>(?<val>.*?)</\1>");

            var res = r2.Match(str);
            Console.WriteLine($"{res.Groups["tag"]}: {res.Groups["val"]}");
        }
    }
}
