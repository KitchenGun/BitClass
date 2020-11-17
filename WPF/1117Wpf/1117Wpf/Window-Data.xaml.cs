using System;
using System.Collections.Generic;
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
    /// Window_Data.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window_Data : Window
    {
        private People people = new People();   //데이터 컬랙션
        private Person per = null;              //데이터 컬렉션 중에 하나를 선택

      

        public Window_Data()
        {
            InitializeComponent();
            per = people[0];
            UpdateDataToUI();
            UpdateListBox();//리스트 박스 초기화
        }

        private void UpdateDataToUI()
        {
            UpdateNameToUI();
            UpdatePhoneToUI();
            UpdateAgeToUI();
            
        }


        #region Data -> UI        private void UpdateNameToUI()        {            if (per == null)
            {
                name.Text = "";
                nameOutput.Content = "";
            }            else
            {
                name.Text = per.Name;
                nameOutput.Content = per.Name;
            }        }        private void UpdatePhoneToUI()        {
            if (per == null)
            {
                phone.Text = "";
                phoneOutput.Content = "";
            }            else
            {
                phone.Text = per.Phone;
                phoneOutput.Content = per.Phone;
            }        }
        private void UpdateAgeToUI()        {            if (per == null)
            {
                age.Text = "";
                ageOutput.Content = "";
            }            else
            {
                age.Text = per.Age.ToString();
                ageOutput.Content = per.Age;
            }        }

        private void UpdateListBox()
        {
            listbox1.Items.Clear();
            foreach(Person per in people)
            {
                listbox1.Items.Add(per);
            }
        }
        #endregion

        #region UI -> Data
        private void Name_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Name = name.Text;
            nameOutput.Content = name.Text;
            //UpdateListBox();
        }

        private void Phone_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Phone = phone.Text;
            phoneOutput.Content = phone.Text;
            //UpdateListBox();
        }

        private void Age_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Age = int.Parse(age.Text);
            ageOutput.Content = age.Text;
            //UpdateListBox();
        }
        #endregion

        private void Listbox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(listbox1.SelectedIndex>=0)
            {
                per = people[listbox1.SelectedIndex];
                UpdateDataToUI();
            }
        }

        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == ""||age.Text =="")
                return;
            people.Add(new Person() { Name = name.Text, Phone = phone.Text,Age = int.Parse(age.Text) });
            // 리스트 박스의 아이템을 갱신한다.
            UpdateListBox();
        }

        private void RemoveButton_Click(object sender, RoutedEventArgs e)
        {
            if (listbox1.SelectedIndex < 0)
            {
                return;
            }

            people.RemoveAt(listbox1.SelectedIndex);
            // 컬렉션에 원소가 없다면 리슽의 현재 아이템이 없도록(per =null) 한다.
            if (people.Count == 0)
                per = null;
            else
                per = people[0];
            // 모든 UI 컨트롤을 갱신한다.
            UpdateDataToUI();//name phone age
            UpdateListBox(); //listbox
        }

        private void UpdateButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == ""|| age.Text == "")
                return;
            per.Name = name.Text;
            per.Phone = phone.Text;
            per.Age = int.Parse(age.Text);
            UpdateDataToUI();
            UpdateListBox();
        }
    }
}
