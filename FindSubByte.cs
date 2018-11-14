using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmTest
{
    class Program
    {
        static int FindSublistIndex(List<byte> dataset, int start, List<byte> sublist)
        {
            var startindex = start;
            do
            {
                var result = true;
                var i = 0;
                foreach (var sub in sublist)
                {
                    var index = -1;
                    //if (startindex == 0)
                        index = dataset.FindIndex(startindex, t => t == sub);
                    //else
                    //    index = dataset.FindIndex(startindex + 1, t => t == sub);
                    //不连续
                    if (i > 0 && index - startindex > 1)
                    {
                        startindex = index - i;
                        result = false;
                        break;
                    }
                    startindex = index;
                    i++;
                }
                if (result)
                    break;
            } while (startindex >= 0);
            return startindex - sublist.Count() + 1;
        }

        static void Main(string[] args)
        {
            byte[] data = { 0x00,0x03,
                0x80, 0x03, 0x02, 0x19, 0x1e, 0x0f, 0xc2,
                0x80, 0x03, 0x02, 0x19, 0x1e, 0x0f, 0xc2 };
            byte[] sublist = { 0x80};
            var result = FindSublistIndex(data.ToList(), 0, sublist.ToList());
            Console.WriteLine("over "+result.ToString());
            Console.ReadKey();
        }
    }
}
