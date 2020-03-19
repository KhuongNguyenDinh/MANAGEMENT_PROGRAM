#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iterator>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class CsvRow
{
	public:
		string const& operator[](size_t index) const
		{
			return m_data[index];
		}
		size_t size() const
		{
			return m_data.size();
		}
		
		void readNextRow(istream& str)
		{
			string line;
			getline(str,line);
			stringstream lineStream(line);
			string cell;
			m_data.clear();
			while(std::getline(lineStream, cell, ','))
			{
				m_data.push_back(cell);	
			}
			if(!lineStream && cell.empty())
			{
				m_data.push_back("");
			}
		}
		private:
			vector<string> m_data;
};

istream& operator>>(istream& str, CsvRow& data)
{
	data.readNextRow(str);
	return str;
}
void create_course(){
	string course;
	cin>>course;
	ofstream myfile;
	myfile.open("created_courses.csv");
	myfile<<course;
	myfile.close();
}
void search_course(){
	ifstream file("Course.csv");
	CsvRow row;

		string info;
		cout<<"Enter course name:"<<"\n";
		cin>>info;
		while(file >> row)
		{
			if(row[1] == info)
			{
				for(int i=0;i<4; i++)
				cout<<" "<<row[i];
			}
			cout<<endl;
		}
	
}
void change_pass(){
	ifstream file("User.csv");
	CsvRow row;
	string password;
		string info;
		cout<<"Enter username:"<<"\n";
		cin>>info;
		cout<<"Enter old password:";
		cin>>password;
		while(file >> row)
		{
			if(row[3] == info)
			{
				if(row[5] == password){
		
				}
			}
			cout<<endl;
		}
}

void search_user_byname(){
	ifstream file("User.csv");
	CsvRow row;

		string info;
		cout<<"Enter user name:"<<"\n";
		cin>>info;
		while(file >> row)
		{
			if(row[2] == info)
			{
				for(int i=0;i<6; i++)
				cout<<" "<<row[i];
			}
			cout<<endl;
		}
}
void search_user_byid(){
	ifstream file("User.csv");
	CsvRow row;
		string info;
		cout<<"Enter user ID:"<<"\n";
		cin>>info;
		while(file >> row)
		{
			if(row[1] == info)
			{
				for(int i=0;i<6; i++)
				cout<<" "<<row[i];
			}
			cout<<endl;
		}
}
void search_user_byaddress(){
	ifstream file("User.csv");
	CsvRow row;
		string info;
		cout<<"Enter user address:"<<"\n";
		cin>>info;
		while(file >> row)
		{
			if(row[4] == info)
			{
				for(int i=0;i<6; i++)
				cout<<" "<<row[i];
			}
			cout<<endl;
		}
}

void login_admin()
{
 string username;
 int count=0,ch;
 string passwd="";
 wrong:
cout<<"Username: ";
 cin>>username;
 cout<<"Password: ";
 while(ch=getch())
 { 
  if(ch == 13){
   if((passwd == "1" && username=="1")){
   cout<<endl<<"Success log in";
   break;
   }
   cout<<"\n Wrong User Name or Password input again! \n\n";
   passwd = "";
   count += 1;
   goto wrong;
  }
  else if(ch==8){
   if(passwd.length()>0){
    cout<<"\b \b";
    passwd.erase(passwd.length()-1); 
   }
  }
  else{
  cout<<"*";
  passwd += ch;
  }
}
}



void login_professor()
{
 int username;
 int count=0,ch;
 string passwd="";
 wrong:
cout<<"Username: ";
 cin>>username;
 cout<<"Password: " ;
 int uname[100];
 int count1=0;
 uname[0]=1001;
 for(int i= 1;i<5;i++){
 uname[i] = uname[i-1]+1;
 if(username == uname[i-1])
 count1++;
}
 while(ch=getch())
 { 
  if(ch == 13){
   if((passwd == "1" && count1 == 1 )){
   cout<<endl<<"Success log in";
   break;
   }
   cout<<"\n Wrong User Name or Password input again! \n\n";
   passwd = "";
   count += 1;
   goto wrong;
  }
  else if(ch==8){
   if(passwd.length()>0){
    cout<<"\b \b";
    passwd.erase(passwd.length()-1); 
   }
  }
  else{
  cout<<"*";
  passwd += ch;
  }
}	
}

void login_student(string username){
 int count=0,ch;
 string passwd="";
 wrong:
 	cout<<"Username:";
 	cin>>username;
 cout<<"Password: " ;
 string uname[100];
 int count1=0;
 uname[0]="1752001";
 uname[1]="1752002";
 uname[2]="1752003";
 uname[3]="1752004";
 uname[4]="1752005";
 for(int i=0;i<5;i++){
 	if(username == uname[i])
 		count1++;
 }
 while(ch=getch())
 { 
  if(ch == 13){
   if((passwd == "1" && count1==1  )){
   cout<<endl<<"Success log in";
   break;
   }
   cout<<"\n Wrong User Name or Password input again! \n\n";
   passwd = "";
   count += 1;
   goto wrong;
  }
  else if(ch==8){
   if(passwd.length()>0){
    cout<<"\b \b";
    passwd.erase(passwd.length()-1); 
   }
  }
  else{
  cout<<"*";
  passwd += ch;
  }
}
}
void view_profile(string a){
	ifstream file("Profile.csv");
	CsvRow row;
		string info;
		while(file >> row)
		{
			if(row[1] == a)
			{
				cout<<"Full Name: "<<row[0]<<endl;
				cout<<"Student ID:"<<row[1]<<endl;
				cout<<"Registered Credits:"<<row[2]<<endl;
				cout<<"GPA: "<<row[3]<<endl;
				cout<<"Address: "<<row[4]<<endl;
				cout<<"Registered courses: ";
				for(int i=5;i<9;i++)
				cout<<row[i]<<" | ";
				cout<<endl;
				cout<<"Courses in current semester: ";
				ifstream file("Course.csv");
				while(file>>row)
				{
						if(row[0] != "ID")
					cout<<row[1]<<" | ";
				}
			}
			cout<<endl;
		}
}

int main()
{	
	string type;
	d:
	if (system("CLS")) system("clear");
	cout<<"\t ASSIGNMENT FUNDAMENTAL OF PROGRAMMING \t"<<endl;
	cout<<"Login as 1.Admin 2.Professor 3.Student\t:\t";
	int login;
	int func;
	cin>>login;
	if(login == 1){
		
		login_admin();
		cout<<endl;
		a:
		cout<<"Enter 1 to search user in the system."<<endl;
		
		cin>>func;
			if(func == 1){
				int func1;
				cout<<"Search by 1.ID 2.Name 3.Adress"<<endl;
				cin>>func1;
				if(func1 == 1)
				search_user_byid();
				if(func1 == 2)
				search_user_byname();
				if(func1 == 3)
				search_user_byaddress();
			}
		cout<<"Enter 1 to continue , 0 to logout."<<endl;
		cin>>type;
		if(type=="1")
		goto a;
		if(type=="0")
		goto d;
		
	}
	/*if(login == 2){
		b:
		login_professor();
		cout<<endl;
		cout<<"2.Create course"<<endl;
		create_course();
	}*/
	
	if(login == 3){
		int func;
		string a;
		cout<<"Username:";
		cin>>a;
		login_student(a);
		cout<<endl;
		c:
		cout<<"Enter 1 search course by name:"<<endl;
		cout<<"Enter 2 view profile:"<<endl;
		cin>>func;
		if(func==1)
		search_course();
		if(func==2)
		view_profile(a);
		cout<<"Enter 1 to continue , 0 to logout."<<endl;
		cin>>type;
		if(type=="1")
		goto c;
		if(type=="0")
		goto d;
	}
}
