using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{
    class SimulData
    {
        private int count;
        public int Count { get { return count; } }

        private int inputcount;
        public int InputCount { get { return inputcount; } }

        private int outputcount;
        public int OutputCount { get { return outputcount; } }

        private int resultmoney;
        public int ResultMoney { get { return resultmoney; } }


        public SimulData(int _count,int _inputcount,int _outputcount,int _resultmoney)
        {
            count = _count;
            inputcount = _inputcount;
            outputcount = _outputcount;
            resultmoney = _resultmoney;
        }
    }
}
