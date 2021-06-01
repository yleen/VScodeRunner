using namespace std;
struct A
{
	char name;
};
struct A2
{
	A2():name('A'){}
	char name;
};
class B
{
public:
	int age;
};

class B2
{
   public:
      void setAge( int age );
      int getAge( void );
      B2();   // 这是构造函数声明
      ~B2();  // 这是析构函数声明
 
   private:
      int age;
};

int main(){
	A a={'a'};
	A2 a2={'a'};
	B b={1};
	B2 b2={1};
	return 0;
}

