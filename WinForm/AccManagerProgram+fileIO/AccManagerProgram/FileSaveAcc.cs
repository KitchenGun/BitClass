using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{
    [Serializable]
    class FileSaveAcc
    {
        #region 프로퍼티 

        //계좌 정보 
        private readonly string type;
        public string Type { get { return type; } }

        private readonly string id;
        public string Id { get { return id; } }

        private readonly string name;
        public string Name { get { return name; } }

        public int Balance { get; private set; }

        private readonly DateTime stime;
        public DateTime Stime { get { return stime; }}
        #endregion

        public FileSaveAcc(string _type, string _id, string _name, int balance, DateTime _stime)
        {
            type = _type;
            id = _id;
            name = _name;
            Balance = balance;
            stime = _stime;
        }
    }
}
