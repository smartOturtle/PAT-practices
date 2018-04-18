using System;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int size=int.Parse(Console.ReadLine());
            var nums = Console.ReadLine().Split(' ');
            double sum = 0;
            var legalSize = 0;
            foreach (var num in nums)
            {
                double result;
                if((num.Length - num.IndexOf('.') <= 3|| num.IndexOf('.') == -1) &&
                    double.TryParse(num, out  result)&& result >= -1000 && result <= 1000)
                {
                    sum += result;
                    legalSize++;
                }
                else Console.WriteLine("ERROR: "+num+" is not a legal number");
            }
            switch (legalSize)
            {
                case 0:
                    Console.WriteLine("The average of 0 numbers is Undefined");
                    break;
                case 1:
                    Console.WriteLine("The average of 1 number is {0:F2}",sum);
                    break;
                default:
                    Console.WriteLine("The average of {0} numbers is {1:F2}",legalSize,sum/legalSize);
                    break;
            }
        }
    }
}
