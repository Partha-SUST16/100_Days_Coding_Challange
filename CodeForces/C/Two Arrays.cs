using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Console = System.Console;

namespace TwoArrays
{
    public class problemC
    {
        static void Main(string[] args)
        {
            long mod = 1000000007;
            var inp = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = inp[0];
            int m = inp[1];

            var arr = new long[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = 1;
            }
            for (int i = 1; i < 2 * m; i++)
            {
                long curent = arr[0];
                for (int j = 1; j < n; j++)
                {
                    curent = (curent + arr[j]) % mod;
                    arr[j] = curent;
                }
            }
            var ans = 0L;
            for (int i = 0; i < n; i++)
            {
                ans = (ans + arr[i]) % mod;
            }
            Console.WriteLine(ans);
        }

    }
}