using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _1123WebService.localhost;

namespace _1123WebService
{
    class Program
    {
        static void Main(string[] args)
        {
            CalService sv = new CalService();
            Console.WriteLine(sv.Add(10, 20));
            Console.WriteLine(sv.Sub(10, 20));
            Console.WriteLine(sv.Mul(10, 20));
        }
    }
}
