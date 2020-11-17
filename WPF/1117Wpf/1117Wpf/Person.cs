using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1117Wpf
{
    class Person : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Name"));
            }
        }

        private string phone;
        public string Phone
        {
            get { return phone; }
            set
            {
                phone = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Phone"));
            }
        }

        private int? age;
        public int? Age
        {
            get { return age; }
            set
            {
                age = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Age"));
            }
        }

        public override string ToString()
        {
            return Name + " : " + Phone + " : " + Age;
        }
    }

    class People : List<Person>
    {
        public People()
        {
            Add(new Person { Name = "홍길동", Phone = "010-1111-1111", Age = 10 });
            Add(new Person { Name = "일지매", Phone = "010-2222-1111", Age = 20 });
            Add(new Person { Name = "임꺽정", Phone = "010-3333-1111", Age = 30 });
        }
    }

}
