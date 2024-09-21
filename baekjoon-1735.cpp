#include <iostream>

using namespace std;

int ucld_hoze(int a, int b) {
	if(b>a) swap(a,b);
	
	if(a%b==0) return b;
	else return ucld_hoze(a%b, b);
}

int main(void) {
	int a, b, c, d, temp;
	cin >> a >> b >> c >> d;
	
	temp=ucld_hoze(a,b);
	b/=temp;
	a/=temp;
	
	temp=ucld_hoze(c,d);
	d/=temp;
	c/=temp;

	temp=ucld_hoze(b, d);
	
	int bunja, bunmo;
	
	bunja= a*(d/temp)+c*(b/temp);
	bunmo= b*(d/temp);
	temp=ucld_hoze(bunja,bunmo);
	
	cout << bunja/temp << " " << bunmo/temp;
	
	
	return 0;
}
