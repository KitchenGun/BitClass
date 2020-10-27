using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace winformSQL1027
{
    class Customer
    {
        public int CID { get; set; }
        public string Name { get; set; }
        public string Phone { get; set; }
        public string Addr { get; set; }

        public Customer(int _pid, string _name, string _phone, string _addr)
        {
            CID = _pid;
            Name = _name;
            Phone = _phone;
            Addr = _addr;
        }

    }
}
