#include<bits/stdc++.h>

using namespace std;


struct node{

	int data;
	node *next;

};


class LL{

	node *head,*tail;

	int length;

public:
    
	LL(){

        	head = NULL;
		tail = NULL;
		length = 0;

	}


    
	void in_end(int data){
       
 		node *tmp = new node;
        
		tmp->data = data;
        
		tmp->next = NULL;
	
        length++;
		if(!head) head = tmp;

		if(!tail) {tail = tmp; return;}
		tail->next = tmp;

		tail = tmp;
	}

	void in_beg(int n){

        	node *tmp = new node;

	        tmp->data = n;
	
        tmp->next = head;
	
        head = tmp;
	
        if(!tail) tail = tmp;

	        length++;
	}

	bool fill1(int x, int n){

        	bool stat = false;

        	if(length + x > n || head == tail) return stat;

        	node* tra = head;
	
        while(tra->next){

                	if(tra->data > 1 && tra->next->data > 1) {stat = true; break;}

	        	tra = tra->next;

        	}
        
		if(!stat) return stat;

	        length+=x;
        
		while(x--){
            
			node *tmp = new node;
            
			tmp->data = 1;
            
			tmp->next = tra->next;
            
			tra->next = tmp;
            
			tra = tmp;
        
		}

	        return stat;

	}
	void display(){
		node* tra = head;

        	while(tra){
	
            cout << tra->data << " ";
	
            tra = tra->next;
	
        }

	        cout << "\n";

	}

    
    int getLength() {return length;}

};


int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	
	int t = 1; cin >> t;

		for(int j = 1; j <= t; j++){

	    
	    	int n, a, b, c;
	    
		  	cin >> n >> a >> b >> c;
			LL arr;
	    
			a-=c; b-=c;
			while(c--) arr.in_beg(n);
			bool stat = 1;

			if(a + b + arr.getLength() > n) stat = 0;
			else{

				while(a--) arr.in_beg(n-1);

			        while(b--) arr.in_end(n-1);
		
	        if(n - arr.getLength() > 0)
				stat = arr.fill1(n - arr.getLength(), n);
		        }

	    	if(arr.getLength() != n) stat = 0;

	   	cout << " Case #" << j << ": ";
                if(stat) arr.display();

	        else cout << "IMPOSSIBLE\n";

		}

		return 0;

}