using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace _1119Wpf관리프로그램
{
    class SaveToExcel
    {

        static Microsoft.Office.Interop.Excel.Application excelApp = null;
        static Microsoft.Office.Interop.Excel.Workbook workBook = null;
        static Microsoft.Office.Interop.Excel.Worksheet workSheet = null;
        public static void SaveAcc(Acclist acclist)
        {
            try
            {
                string desktopPath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
                // 바탕화면 경로 
                string path = Path.Combine(desktopPath, "Excel.xlsx");
                // 엑셀 파일 저장 경로 
                excelApp = new Microsoft.Office.Interop.Excel.Application();
                // 엑셀 어플리케이션 생성 
                workBook = excelApp.Workbooks.Add();
                // 워크북 추가 
                workSheet = workBook.Worksheets.get_Item(1) as Microsoft.Office.Interop.Excel.Worksheet;
                // 엑셀 첫번째 워크시트 가져오기 
                workSheet.Cells[1, 1] = "계좌번호";
                workSheet.Cells[1, 2] = "이름";
                workSheet.Cells[1, 3] = "잔액";
                workSheet.Cells[1, 4] = "일시";
                // 엑셀에 저장할 개 데이터 
                int i = 0;
                foreach(Account acc in acclist)
                {
                    
                    workSheet.Cells[2 + i, 1] = acc.accId;
                    workSheet.Cells[2 + i, 2] = acc.accName;
                    workSheet.Cells[2 + i, 3] = acc.accMoney;
                    workSheet.Cells[2 + i, 4] = acc.accTime;
                    i++;
                }
                i = 0;
                workSheet.Columns.AutoFit();
                // 열 너비 자동 맞춤 
                workBook.SaveAs(path, Microsoft.Office.Interop.Excel.XlFileFormat.xlWorkbookDefault);
                // 엑셀 파일 저장 
                workBook.Close(true); excelApp.Quit();
            }
            finally
            {
                ReleaseExcelObject(workSheet);
                ReleaseExcelObject(workBook);
                ReleaseExcelObject(excelApp);
            }
        } 
        /// <summary> 
        /// 액셀 객체 해제 메소드 
        /// </summary>  <param name="obj"></param> 
        static void ReleaseExcelObject(object obj)
        {
            try
            {
                if (obj != null)
                {
                    Marshal.ReleaseComObject(obj);
                    // 액셀 객체 해제
                    obj = null;
                }
            }
            catch (Exception ex)
            {
                obj = null; throw ex;
            }
            finally
            {
                GC.Collect();
                // 가비지 수집 
            }
        }

        //프로그램 실행될때 Load 
        public static void FileLoad(ref Acclist acc)
        {
            string desktopPath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            // 바탕화면 경로 
            string path = Path.Combine(desktopPath, "Excel.xlsx");
            // 엑셀 파일 저장 경로 
            excelApp = new Microsoft.Office.Interop.Excel.Application();
            // 엑셀 어플리케이션 생성 
            workBook = excelApp.Workbooks.Open(path);
            // 워크북 추가 
            workSheet = workBook.Worksheets.get_Item(1) as Microsoft.Office.Interop.Excel.Worksheet;
            // 엑셀에 저장할 개 데이터 
            Account account=new Account();
            for (int i = 0;i<;i++)
            {

                account.accId = workSheet.Cells[2 + i, 1];
                account.accName=workSheet.Cells[2 + i, 2];
                account.accMoney=workSheet.Cells[2 + i, 3];
                account.accTime=workSheet.Cells[2 + i, 4];
                acc.Add(account);
            }
        }
    }
}
