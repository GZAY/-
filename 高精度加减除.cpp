//1.д�����ֹ۲���ɣ�ÿһ���쳲��������е�ǰ��������̣�
//2.תΪ��쳲��������е�n��n+1�Ҫ�õ���ʽ�����ǵݹ�ʽ��
//3.nȡ���٣�������n��С������101λû�б仯
//4.������c���Զ����������ֱ�����㣬��Ҫ�ֹ���д�����ӷ��ͳ�����������
#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int n=300;

string add(string a,string b)
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	long long lenA=a.length();
	long long lenB=b.length();
	long long len=max(lenA,lenB)+10;
	//��ת���ڴӵ�λ�����
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans(len,'0');//��ʼ����Ϊlen����ȫ��Ϊ�ַ�0
	for(int i=0;i<lenA;++i)
	{
		ans[i]=a[i];
	}
	int tmp=0;
	for(int i=0;i<len;++i)//tmp����һλ��Ӻ�Ľ�λ
	{
		if(i<b.length())
			tmp+=(ans[i]-'0')+(b[i]-'0');//�ַ���ת����
		//��bΪ�̵��ַ�������b������λ�ü����ֻ��Ҫ��a��ֵ��tmp
		else
			tmp+=(ans[i]-'0');
		ans[i]=tmp%10+'0';
		tmp/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}

int cmp(string a,string b)
{
	unsigned long i1=a.find_first_not_of('0');
	if(i1==string ::npos)a='0';
	else a.substr(i1);

	unsigned long i2=b.find_first_not_of('0');
	if(i2==string ::npos)b='0';
	else b.substr(i2);


	if(a.length()>b.length())return 1;
	else if(a.length()<b.length())return -1;
	else{//�������
		if(a<b)return -1;
		if(a>b)return 1;
		else return 0;
	}
}
//�˴�aһ������b
string subtract(string a,string b)
{
//�����ļ������棬a����С��b����ʱ�����Ϊ����������ab��������Ĵ���
	//1.��ת
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//2.��λ������
	for(int i=0;i<b.length();++i)
	{
		if(a[i]>=b[i]){
			a[i]=a[i]-b[i]+'0';
		}else{
			int k=1;
			while(a[i+k]=='0'){
				a[i+k]='9';
				k++;
			}
			//������Ա�֤i+k��һλ�ϲ���0
				a[i+k]=a[i+k]-'1'+'0';//����ת�ַ���
				a[i]=(a[i]-'0'+10)-(b[i]-'0')+'0';
		}
	}
	reverse(a.begin(),a.end());
	if(a.find_first_not_of('0')==string :: npos)return "0";
	return a.substr(a.find_first_not_of('0'));
}
	
void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}
	//����ת���ɼ���
string divide(string a,string b)
{
	//ֻ����a<b�����
	string ans="0.";//��ĩβ׷��0��
		for(int i=0;i<101;++i)
		{
			a.append("0");
			int t=0;
			while(cmp(a,b)>=0)
			{
				a=subtract(a,b);//a>=b��ͣ������
				t++;
			}
			string t_str;
			i2s(t,t_str);
			ans.append(t_str);
		}
		return ans;
}
int main(int argc, const char *argv[]){
	string a="1";
	string b="1";
	for(int i=3;i<=n;++i)
	{
		string tmp=b;
		b=add(a,b);
		a=tmp;
	}
	
	string ans = divide(a,b);
	cout<<ans<<endl;
	cout<<ans.length()-2<<endl;
	return 0;
}