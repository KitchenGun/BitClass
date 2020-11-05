using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace _1105OpenApiSearch
{
    class WbTranslate
    {
        public static string Translate(string msg, string start, string end)
        {
            //기본요청 url
            string url = "https://openapi.naver.com/v1/papago/n2mt";
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "IsBGXByHROv6tMY7cRgC");
            request.Headers.Add("X-Naver-Client-Secret", "vTtHSQwM1v");
            request.Method = "POST";
            string query = msg;
            //요청
            byte[] byteDataParams = Encoding.UTF8.GetBytes("source=" + start + "&target=" + end + "&text=" + query);
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = byteDataParams.Length;
            Stream st = request.GetRequestStream();
            st.Write(byteDataParams, 0, byteDataParams.Length);
            st.Close();
            //응답
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            Stream stream = response.GetResponseStream();
            StreamReader reader = new StreamReader(stream, Encoding.UTF8);
            string text = reader.ReadToEnd();
            stream.Close();
            response.Close();
            reader.Close();
            return text;
        }
    }
}
