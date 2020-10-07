﻿using System;
using System.Collections.Generic;
using System.Text;

namespace _1007
{
    class AccList
    {
        #region 생성자&property
        public int Id { get; private set; }
        public int InputMoney            { get; private set; }
        public int OutputMoney          { get; private set; }
        public int Balance                   { get; private set; }
        public DateTime CurTime      { get; private set; }


        public AccList(int id,int input, int output, int balance)
        {
            Id = id;
            InputMoney = input;
            OutputMoney = output;
            Balance = balance;
            CurTime = DateTime.Now;

        }
        #endregion

        public override string ToString()
        {
            String str = String.Format("{0}\t{1}\t{2}\t{3}\t{4}\t{5}",
                Id, InputMoney, OutputMoney, Balance,
                CurTime.ToShortDateString(), CurTime.ToShortTimeString());

            return str;
        }
    }
}
