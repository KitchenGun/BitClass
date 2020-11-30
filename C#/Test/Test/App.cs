using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class App
    {
		#region 싱글톤
		private App() { } //1.생성자 은닉
							  //2.프로퍼티 선언
		static public App Singleton { get; private set; }
		//3. static 생성자에서 객체 생성 (단 한번 호출되는 문장)
		static App()
		{
			Singleton = new App();//단일체 생성
		}
		#endregion

		private void MenuPrint()
		{
			Console.WriteLine("***********************************************");
			Console.WriteLine("* [ESC] 프로그램 종료");
			Console.WriteLine("* [F1] 입력기능");
			Console.WriteLine("* [F2] 삭제 기능");
			Console.WriteLine("* [F3] 검색 기능");
			Console.WriteLine("* [F4] 수정 기능");
			Console.WriteLine("***********************************************");
		}

		public void Run()
		{
			ConsoleKeyInfo ReadKey;
			while (true)
			{
				Console.Clear();
				MenuPrint();
				ReadKey = Console.ReadKey();
				switch (ReadKey.Key)
				{
					case ConsoleKey.F1: StuManager.Singleton.InsertStudent(); break;
					case ConsoleKey.F2: StuManager.Singleton.RemoveStudent(); break;
					case ConsoleKey.F3: StuManager.Singleton.SearchStudent(); break;
					case ConsoleKey.F4: StuManager.Singleton.EditStudent(); break;
					case ConsoleKey.Escape: return;
						//default: Console.WriteLine("Not defined menu"); break;
				}
				fnEnter();
			}
		}
		private void fnEnter()
		{
			Console.WriteLine("Press Any Key\n");
			Console.ReadLine();
		}
	}

	
}
