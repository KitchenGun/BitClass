using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace AccManagerProgram
{

    class FileIO
    {
        #region 싱글톤
        //1. 생성자 은닉
        private FileIO()
        {

        }
        //2. 프로퍼티 선언
        static public FileIO Singleton { get; private set; }
        //3. static 생성자에서 객체 생성(단 한번 호출되는 문장)
        static FileIO()
        {
            Singleton = new FileIO();
        }
        #endregion
        static String filename = "Data.txt";

        #region byte[] 기반 IO 수행
        public static void Write()
        {
            List<FileSaveAcc> acclist = new List<FileSaveAcc>();
            foreach (KeyValuePair<string, NormalAcc> acc in AccManager.Singleton.AccList)
            {
                acclist.Add(new FileSaveAcc(acc.Value.Type.ToString(), acc.Value.Id, acc.Value.Name, acc.Value.Balance, acc.Value.Stime));
            }
            // 1) 파일 스트림 생성
            Stream outStream = new FileStream(filename, FileMode.Create);

            // 2) 객체의 정보를 문자열로 변환 -> 바이트배열로 변환
            String str = String.Empty;
            foreach (FileSaveAcc acc in acclist)
            {
                str += acc.Type + "#";
                str += acc.Id + "#";
                str += acc.Name + "#";
                str += acc.Balance + "#";
                str += acc.Stime + "@";
            }
            byte[] StrByte = Encoding.UTF8.GetBytes(str);

            // 3) 변환한 byte 배열을 파일 스트림을 통해 파일에 기록
            outStream.Write(StrByte, 0, StrByte.Length);

            // 4) 파일 스트림 닫기
            outStream.Close();
        }
        public static AccountType Typeset(string type)
        {
            switch (type.ToString())
            {
                case "NORMALACC":
                    return AccountType.NORMALACC;
                case "PERDEPOSIT":
                    return AccountType.PERDEPOSIT;
                case "FUNDACC":
                    return AccountType.FUNDACC;
            }
            return AccountType.NON;

        }
        public static void Read()
        {

            // 1) 파일 스트림 생성
            Stream inStream = new FileStream(filename, FileMode.Open);
            if(inStream==null)
            {
                throw new Exception("파일없음");
            }
            // 2) rBytes의 길이만큼(8바이트) 데이터를 읽어 rBytes에 저장
            byte[] rBytes = new byte[256];
            inStream.Read(rBytes, 0, rBytes.Length);

            // 3) byte[] -> string
            string str = Encoding.UTF8.GetString(rBytes);
            Console.WriteLine(str);
            //객체화
            List<FileSaveAcc> acclist = new List<FileSaveAcc>();
            string[] split1 = str.Split('@');
            for (int i = 0; i < split1.Length - 1; i++)
            {
                string[] split2 = split1[i].Split('#');
                FileSaveAcc acc = new FileSaveAcc(split2[0], split2[1], split2[2], int.Parse(split2[3]), DateTime.Parse(split2[4]));
                acclist.Add(acc);
            }

            foreach(FileSaveAcc acc in acclist)
            {
                AccManager.Singleton.AccList.Add(acc.Id, new NormalAcc(Typeset(acc.Type), acc.Id, acc.Name, acc.Balance, acc.Stime));
            }
            // 4) 파일 스트림 닫기
            inStream.Close();
        }

      
        #endregion
        /* #region 직렬화
         public static void Write(List<FileSaveAcc> acclist)
         {
             foreach (KeyValuePair<string,NormalAcc> acc in AccManager.Singleton.AccList)
             {
                 acclist.Add(new FileSaveAcc(acc.Value.Type, acc.Value.Id, acc.Value.Name, acc.Value.Balance, acc.Value.Stime));
             }
            Stream ws = new FileStream(filename, FileMode.Open);
             BinaryFormatter serializer = new BinaryFormatter();
             serializer.Serialize(ws, acclist);


             ws.Close();
         }
         public static void Read(ref List<FileSaveAcc> acclist)
         {
             try
             {
                 Stream rs = new FileStream(filename, FileMode.Create);
                 BinaryFormatter deserializer = new BinaryFormatter();

                 acclist = (List<FileSaveAcc>)deserializer.Deserialize(rs);
                 foreach(FileSaveAcc acc in acclist)
                 {
                     AccManager.Singleton.AccList.Add(acc.Id, new NormalAcc(acc.Type, acc.Id, acc.Name, acc.Balance, DateTime.Parse(acc.Stime)));
                 }
                 rs.Close();
             }
             catch
             {
             }
         }
         #endregion
        */
    }
}
