using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _1117Wpf
{
    /// <summary>
    /// WindowDataBinding3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class WindowDataBinding3 : Window
    {
        //People people = new People(); xaml의 윈도우리소스로 이동(1/2)
        public WindowDataBinding3()
        {
            InitializeComponent();
            //binding 처리[컬렉션 데이터와 컨트롤과의 바인딩]
            //--컬렉션의 첫번째 person 객체와 컨트롤의 속성이 연결된다
            // cur의 개념이 있다.
            //panel.DataContext = people; xaml의 패널로 이동(2/2)
        }

        private void eraseButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            Person person = (Person)view.CurrentItem;
            person.Name = "";
            person.Phone = "";
            person.Age = null;
            person.Male = null;
        }

        private void Prev_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToPrevious();
            if (view.IsCurrentBeforeFirst)
            {
                view.MoveCurrentToFirst();
            }
        }

        private void Next_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToNext();
            if (view.IsCurrentAfterLast)
            {
                view.MoveCurrentToLast();
            }
        }

        private void RemoveButton_Click(object sender, RoutedEventArgs e)
        {
            People people = (People)FindResource("people");
            //컬렉션 데이터 삭제
            //리스트 박스 갱신을 위해서 컬렉션 클래스 부모를 변경처리함
            if (listbox.SelectedIndex >= 0) 
            {
                people.RemoveAt(listbox.SelectedIndex);
            }
        }
    }
}
