using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace winformSQL1027
{
    class Sale
    {
        public int CID { get; set; }
        public int PID { get; set; }
        public int  Count { get; set; }
        public DateTime Datetime { get; set; }

        public Sale(int _cid, int _pid, int _count, DateTime _datetime)
        {
            PID = _pid;
            CID = _pid;
            Count = _count;
            Datetime = _datetime;
        }

    }
}
