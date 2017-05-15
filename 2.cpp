#include <iostream>
#include <math.h>
#include <string>
using namespace std;
template <class Type>
class mass
{
public:
	mass(const mass<Type>& a);
	mass(const int s);
	~mass() {delete[]array;}
	void getarray()
	{
		cout<<"Your array:"<<endl;
		for(int i=0;i<size; i++)
		{
			cout<<"element("<<i+1<<"): "<<array[i]<<endl;
		}
	}
		
protected:
	int	size;
	Type* array;
};
template <class Type> mass<Type>::mass(const mass<Type>& a)
{
	size=a.size;
	array=new Type[size];
	for(int i=0;i<size; i++)
	array[i]=a.array[i];
}
template<class Type> mass<Type>::mass(const int s)
{
	size=s;
	array=new Type[size];
	cout<<"Enter array: "<<endl;
	for(int i=0;i<size;i++)
	cin>>array[i];
}
class human
{ 
 protected:
   string name1,name2;
   int age;
 public:
   human();
   human(const human&s);
   human(string name1,string name2,int age);
   void getData();
   void zmina_age();
   virtual ~human();
   //operator =
   human operator =(const human& a)
   {
   	age=a.age;
	name1=a.name1;
	name2=a.name2;
	return *this;
   }
   	//out operator
	friend ostream& operator<<(ostream& s,const human& a)
	{
		s << "human: " << a.name1 << " " << a.name2 <<" :"<<a.age<<endl;
		return s;
	}
	//in operator
	friend istream& operator>>(istream& s, human& a)
	{
		cout<<"Enter name/surname and age: ";
		s>>a.name1>>a.name2>>a.age;
		return s;
	}
};
//constructor for copy
human::human(const human&s)
{	
	age=s.age;
	name1=s.name1;
	name2=s.name2;
}
//the default constructor
   human::human()
{

 name1="Ivan";
 name2="Golovko";
 age=19;
}
//constructor with parameter
  human::human(string nam1,string nam2,int ag)
  {
  	name1=nam1;
  	name2=nam2;
  	age=ag;
  }
//function for change bew age
void human::zmina_age()
{cout<<"Enter new age: ";
cin>>age;
}
//destructor
human::~human() 
{}
 //function which shows information about object
void human::getData()
{
 cout<<name1<<" "<<name2<<" :"<<age<<endl;
}
//derived class
class student : public human
{
private:
	string*predmet;
	int*otchinka;
	int n;
public:
	~student();
	void getData();
	void change_Data();
	student();
	friend istream& operator>>(istream& s, student& a);
	friend ostream& operator<<(ostream& s, const student& a);
	//operator =
	student operator =(const student& a)
	{
	student b;
	delete []predmet;
	delete []otchinka;
	n=a.n;
	age=a.age;
	name1=a.name1;
	name2=a.name2;
	predmet=new string[n];
	otchinka=new int[n];
	for(int i=0;i<n;i++)
	{
		predmet[i]=a.predmet[i];
		otchinka[i]=a.otchinka[i];
	}	
	return *this;
	}
	

	//the default constructor 
	student(const student & s):human(s)
	{
		n=s.n;
		predmet= new string[n];
 		otchinka=new int[n];
 		for(int i=0;i<n;i++)
  		{   	
			predmet[i]=s.predmet[i];
  		 	otchinka[i]=s.otchinka[i];
		}
	};
	//constructor with parameter
	student(string nam1,string nam2,int ag,string predme[],int*otchink,int u) : human(nam1,nam2,ag)
	 {  
	 	n=u;
  		predmet= new string[u];
 		otchinka=new int[u];
  		for(int i=0;i<u;i++)
  	 	{
  	  		otchinka[i]=otchink[i];
  	  		predmet[i]=predme[i];
		}
 	 }
};
	//the default constructor
    student::student()
	{
   		 n=2;
 		predmet= new string[n];
 		otchinka=new int[n];
	 	predmet[0]="Mathematical analysis";
 		otchinka[0]=4;
	 	predmet[1]="Linear algebra";
		otchinka[1]=3;
	}
 	void student::change_Data()
 	{   
 		int vubo;
 		cout<<"Do you want change name and surname name true(1)/false(0): ";
 		cin>>vubo;
 		if(vubo)
 		{
 			cout<<"Enter new name and surname: ";
 			cin>>name1>>name2;
		}
		cout<<"Do you want change subjects true(1)/false(0): ";
		cin>>vubo;
		if(vubo)
 		{
 			int suma;
 			cout<<"Enter new syma subject number: ";
 			cin>>suma;
 			int*ot=new int[n];
			string*pr=new string[n];
 			for(int i=0;i<n;i++)
 			{
 				pr[i]=predmet[i];
 				ot[i]=otchinka[i];
			}
			delete []otchinka;
			delete []predmet;
			n=n+suma;
			otchinka=new int[n];
			predmet=new string[n];
			for(int i=0;i<n;i++)
			{
				if(i<n-suma)
				{
					predmet[i]=pr[i];
					otchinka[i]=ot[i];
				}
				else
				{
					cout<<"Enter new subject and mark "<<i+1<<" : ";
					cin>>predmet[i];
					cin>>otchinka[i];
				}
			}
			delete []pr;
			delete []ot;	
		}
		cout<<"Do you want change age true(1)/false(0): ";
 		cin>>vubo;
		if(vubo)
		{
			cout<<"Enter new age: ";
			cin>>age;
		}
 	}
 	//function which shows information about object
 	void student::getData()
 	{
 	 	cout<<name1<<" "<<name2<<" :"<<age<<endl;
 		for(int i=0;i<n;i++)
 			cout<<predmet[i]<<": "<<otchinka[i]<<endl;
 	}
	 //destructor
 	student::~student() 
	{
		delete []otchinka;
		delete []predmet;
	}
	//out operator
	ostream& operator<<(ostream& s, const student& a)
	{
		s << "student: " << a.name1 << " " << a.name2 <<endl;
		for(int i=0;i<a.n;i++)
		{
			s<<a.predmet[i]<<" : "<<a.otchinka[i]<<endl;
		}
		return s;
	}
	//in operator
	istream& operator>>(istream& s, student& a)
	{
		delete []a.predmet;
		delete []a.otchinka;
		cout<<"Enter name/surname and age: ";
		s>>a.name1>>a.name2>>a.age;
		cout<<"Enter the number of items: ";
		s>>a.n;
		a.otchinka=new int[a.n];
		a.predmet=new string[a.n];
		for(int i=0;i<a.n;i++)
		{
			cout<<"subject "<<i+1<<" :";
			s>>a.predmet[i];
			cout<<"mark: ";
			s>>a.otchinka[i];
		}
		return s;
	}
int main()
{
	bool vubor;
	cout<<"Enter true(1) for default or false(0) for own change: ";
	cin>>vubor;
	if (vubor)
	{
		//mass<char> n;
	    //n.getarray();
		mass<float> m(2);
		m.getarray();
		mass<string> jo(1);
		jo.getarray();
		mass<student> k(1);
		k.getarray();
		//cin>>s;*/
		//human g("Masha","Kol",19);
		//s=g;
		//cout<<s;
		//student K;
		//cin>>K;
		//cout<<K;
		/*student M(K);
		M.getData();
		K.getData();
		K.change_Data();
		M=K;
		M.getData();*/
	}
	else
	{
		int ag,u;
		string nam1,nam2;
		cout<<"Enter name and surname: ";
		cin>>nam1>>nam2;
		cout<<"Enter age: ";
		cin>>ag;
		cout<<"Enter the number of items: ";
		cin>>u;
		int*ot=new int[u];
		string*pr=new string[u];
		cout<<"Enter subject/mark:"<<endl;
		for(int i=0;i<u;i++)
		{
			cout<<"subject "<<i+1<<" :";
			cin>>pr[i];
			cout<<"mark: ";
			cin>>ot[i];
		}
		student J(nam1,nam2,ag,&pr[0],&ot[0],u);
		J.getData();
		delete []pr; 
		delete[]ot;
	}
  return 0;
}
