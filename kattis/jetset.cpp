#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << nl

ll n, m, t, a, b, c, k;
string f, s;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll p=0;
	ll start;
	int dat[720]={false};
	vector<pii> oneeight;
	for (int i=0;i<n;i++){
		cin >> a >>b;
		b+=180;
		dat[2*b]=true;
		if (i){
			ll t=b;
			if (b<p){
				swap(b,p);
			}
			if (b-p==180){
				oneeight.pb(pii(b,p));
				continue;
			}
			if (b-p<360-b+p){
				for (int i=p;i<b;i++){
					dat[2*i]=dat[2*i+1]=true;
				}
			} else {
				for (int i=0;i<p;i++){
					dat[2*i]=dat[2*i+1]=true;
				}
				for (int i=b;i<360;i++){
					dat[2*i]=dat[2*i+1]=true;
				}
			}
			p=t;
		} else {
			start=p=b;
		}
	}
	b=start;
	if (b<p){
		swap(b,p);
	}
	if (b-p==180){
		oneeight.pb(pii(p,b));
	} else if (b-p<360-b+p){
		for (int i=p;i<b;i++){
			dat[2*i]=dat[2*i+1]=true;
		}
	} else {
		for (int i=0;i<p;i++){
			dat[2*i]=dat[2*i+1]=true;
		}
		for (int i=b;i<360;i++){
			dat[2*i]=dat[2*i+1]=true;
		}
	}
	if (oneeight.size()<2){
		for (int i=0;i<720;i++){
			if (!dat[i]){
				if (oneeight.empty()){
					double cc=i;
					printf("no %.1f",cc/2-180);
					return 0;
				} else {
					p=oneeight[0].fi;
					b=oneeight[0].se;
					oneeight.pop_back();
					if (i>p*2){
						for (int j=p;j<b;j++){
							dat[j*i]=dat[j*i+1]=true;
						}
					} else {
						for (int i=0;i<p;i++){
							dat[2*i]=dat[2*i+1]=true;
						}
						for (int i=b;i<360;i++){
							dat[2*i]=dat[2*i+1]=true;
						}
					}
				}
			}
		}
	}
	cout<<"yes";
}