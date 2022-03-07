1. given a collection of num which also contain dup generate all unique perm
i.e no two set should look exactly alike 

generate all perm using backtracking and store them in a set 

set<vector<int> > p;
void getPer(vector<int> a, int ind){
    int l=a.size();
    if(ind==l-1){
        p.insert(a);
        return;
    }
    for(int i=ind;i<l;i++){
        swap(a[ind], a[i]);
        getPer(a, ind+1);
        swap(a[ind], a[i]);
    }
    return;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> a;
    p.clear();
    int l=A.size();
    getPer(A, 0);
    vector<vector<int> > ans;
    ans.assign(p.begin(), p.end());
    return ans;
}

2. Combination Sum
Given a collection of numbers give all unique comb of elemnts which sum to n
you can select any num any number of times

for every element you have choice to include it or not and this give rise to two calls incl then backtracking and 
then not included
since any number can be selected any number of time after every call we have to start from first element for removing dupl
com we have to sort the vector first because even if arrangement is diff but element are same in two vec then they are diff
vector for a set

set<vector<int> > s;
void getSum(vector<int> a, vector<int> temp, int sum, int target){
    int l=a.size();
    if(sum==target){
        sort(temp.begin(),temp.end());
        s.insert(temp);
        return;
    }else if(sum>target){
        return;
    }
    
    for(int i=0;i<l;i++){
        temp.push_back(a[i]);
        getSum(a,temp,sum+a[i],target);
        temp.pop_back();
    }
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> temp;
    sort(A.begin(), A.end());
    set<int> uniq(A.begin(), A.end());
    A.assign(uniq.begin(), uniq.end());
    getSum(A,temp,0,B);
    vector<vector<int> > ans;
    ans.assign(s.begin(),s.end());
    s.clear();
    sort(ans.begin(),ans.end());
    return ans;
}

single element only one time
set<vector<int> > s;
void getComb(vector<int> a,vector<int> curr, int ind, int sum, int target){
    int l=a.size();
    if(target==sum){
        sort(curr.begin(),curr.end());
        s.insert(curr);
        return;
    }
    if(sum>target||ind==l){
        return;
    }
    getComb(a,curr,ind+1,sum,target);
    curr.push_back(a[ind]);
    getComb(a,curr,ind+1,sum+a[ind],target);
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    s.clear();
    vector<int> curr;
    getComb(A,curr,0,0,B);
    vector<vector<int> > ans;
    ans.assign(s.begin(),s.end());
    return ans;
}

Palindrome Partioning 
class Solution {
        public:
                bool isPalindrome(string &str, int s, int e) {
                        while (s < e) {
                                if (str[s] != str[e])
                                        return false;
                                s++;
                                e--;
                        }
                        return true;
                }

                void partitionHelper(int i, vector<string> &current, string &s, vector<vector<string> > &ans) {

                        if (i == s.length()) {
                                // we reached the end of the string.
                                // Valid sequence of strings found.
                                ans.push_back(current);
                                return;
                        }

                        for (int j = i; j < s.length(); ++j) {
                                if (isPalindrome(s, i, j)) {
                                        current.push_back(s.substr(i, j - i + 1));
                                        partitionHelper(j + 1, current, s, ans);
                                        current.pop_back();
                                }
                        }
                }

                vector<vector<string> > partition(string s) {
                        vector<vector<string> > ans;
                        vector<string> current;
                        partitionHelper(0, current, s, ans);
                        return ans;
                }
};


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    for(int i=0;i<B;i++){
        while(!dq.empty()&&A[dq.front()]<=A[i]){
            dq.pop_front();
        }
        dq.push_front(i);
    }
    vector<int> ans;
    ans.push_back(A[dq.back()]);
    int n=A.size();
    for(int i=B;i<n;i++){
        while(!dq.empty()&&(i-dq.back()+1>B||A[dq.back()]<A[i])){
            dq.pop_back();
        }
        while(!dq.empty()&&A[dq.front()]<A[i]){
            dq.pop_front();
        }
        dq.push_front(i);
        ans.push_back(A[dq.back()]);
    }
    return ans;
}

spiral print 
classic implementation magic
class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > ret( n, vector<int>(n) );
        	int k = 1, i = 0;
        	while( k <= n * n )
        	{
        		int j = i;
                    // four steps
        		while( j < n - i )             // 1. horizonal, left to right
        			ret[i][j++] = k++;
        		j = i + 1;
        		while( j < n - i )             // 2. vertical, top to bottom
        			ret[j++][n-i-1] = k++;
        		j = n - i - 2;
        		while( j > i )                  // 3. horizonal, right to left 
        			ret[n-i-1][j--] = k++;
        		j = n - i - 1;
        		while( j > i )                  // 4. vertical, bottom to  top 
        			ret[j--][i] = k++;
        		i++;      // next loop
        	}
        	return ret;
        }
    };

    bool compare(string a, string b){
    return a+b<b+a;
    /*int l=min(a.size(),b.size());
    int i=0;
    while(i<l){
        if(a[i]!=b[i]){
            return a[i]<b[i];
        }
        i++;
    }
    if(a.size()>b.size()){
        return a[i]<b[0];
    }else if(a.size()<b.size()){
        return a[0]<b[i];
    }else
    return a<b;*/
}

bool compare(string a, string b){
 slick ------>   return a+b<b+a;
    /*int l=min(a.size(),b.size());
    int i=0;
    while(i<l){
        if(a[i]!=b[i]){
            return a[i]<b[i];
        }
        i++;
    }
    if(a.size()>b.size()){
        return a[i]<b[0];
    }else if(a.size()<b.size()){
        return a[0]<b[i];
    }else
    return a<b;*/
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> s;
    int n=A.size();
    for(int i=0;i<n;i++){
        s.push_back(to_string(A[i]));
    }
    sort(s.begin(),s.end(),compare);
    string ans;
    bool valid=false;
    for(int i=n-1;i>=0;i--){
        ans+=s[i];
        if(s[i]!="0"){
            valid=true;
        }
    }
    if(valid)
    return ans;
    return "0"; 
}

Add one to number
vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    int i=0,temp=1;
    vector<int> ans;
    int zero=0;
    while(i<n){
        if(A[i]==0){
            zero++;
        }else{
            break;
        }
        i++;
    }
    A.erase(A.begin(),A.begin()+zero);
    if(A.size()==0){
        ans.push_back(1);
        return ans;
    }
    i=A.size()-1;
    while(i>=0){
        A[i]+=temp;
        temp=0;
        if(A[i]>=10){
            A[i]=temp%10;
            temp=1;
        }
        ans.push_back(A[i]);
        i--;
    }
    if(temp==1){
        ans.push_back(1);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

---Pascals Triangle
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> >ans;
    ans.resize(A);
    for(int i=0;i<A;i++){
        ans[i].resize(i+1);
        ans[i][0]=1;
        ans[i][i]=1;
    }
    for(int i=2;i<A;i++){
        int l=ans[i].size();
        for(int j=1;j<l-1;j++){
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}

--------Max Dist
class Solution {
    public:
        int maximumGap(const vector<int> &num) {
            if (num.size() == 0) return -1;
            if (num.size() == 1) return 0;
            vector<pair<int, int> > toSort;
            for (int i = 0; i < num.size(); i++) {
                toSort.push_back(make_pair(num[i], i));
            }
            sort(toSort.begin(),toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }
            return ans;
        }
};

--------Next Permutation
vector<int> Solution::nextPermutation(vector<int> &A) {
    int n=A.size();
    if(n<=1){
        return A;
    }
    for(int i=n-1;i>0;i--){
        if(A[i]>A[i-1]){
            int j=i;
            while(j<n&&A[j]>A[i-1]){
                j++;
            }
            swap(A[i-1],A[j-1]);
            reverse(A.begin()+i, A.end());
            return A;
        }
    }
    reverse(A.begin(),A.end());
    return A;
}

---------Anti Diagonals
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int> > ans;
    ans.resize(2*n-1);
    int k=0;
    for(int i=0;i<n;i++){
        int row=0,col=i;
        while(row<=i&&col>=0){
            ans[k].push_back(A[row][col]);
            row++;
            col--;
        }
        k++;
    }
    
    for(int i=1;i<n;i++){
        int row=i,col=n-1;
        while(row<n&&col>=0){
            ans[k].push_back(A[row][col]);
            row++;
            col--;
        }
        k++;
    }
    return ans;
}

---------Hotels Booking
class Solution {
    public:
    
    bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        sort arrival and departure and arrival on the basis of even time
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1) { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);

               store max number of arrival at any point of time i.e max number of active guests at any time 
               and if this number is greater than k then it is not possible
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }
};

---------Flip kadanes implementation

vector<int> Solution::flip(string A) {
    int sum=0,l=0,r=0,ans=0,templ=0,tempr=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]=='0'){
            sum++;
            tempr=i;
            if(sum>ans){
                ans=sum;
                l=templ+1,r=tempr+1;
            }
        }else{
            sum--;
            if(sum<0){
                tempr=i+1,templ=i+1;
                sum=0;
            }
        }
    }
    vector<int> ret;
    if(ans>0){
        ret={l,r};
        return ret;
    }
    return ret;
}

---------Max value of mod(A[i]-A[j])+mod(i-j)

int Solution::maxArr(vector<int> &A) {
    int a=INT_MIN,b=INT_MAX,c=INT_MIN,d=INT_MAX;
    int n=A.size();
    for(int i=0;i<n;i++){
        a=max(a,A[i]+i);
        b=min(b,A[i]+i);
        c=max(c,A[i]-i);
        d=min(d,A[i]-i);
    }
    return max((a-b),(c-d));
}

--------Max unsorted array
vector<int> Solution::subUnsort(vector<int> &A){
	vector<int> ans;
	int n = A.size();
	int i = 0, j = n-1;
	while(i< n - 1 and A[i] <= A[i + 1]){
		i++;
	}
	while(j > 0 and A[j] >= A[j - 1]){
		j--;
	}
	if(i == n - 1){ // if array is already sorted, output -1
		ans.push_back(-1);
		return ans;
	}
	int mn = A[i + 1], mx = A[i + 1];
	for(int k = i; k <= j; k++){
		mx = max(mx, A[k]);
		mn = min(mn, A[k]);
	}
	int l = 0, r = n - 1;
	while(A[l] <= mn and l <= i){
	   	l++;
	}
	while(A[r] >= mx and r >= j){
		r--;
	}
	ans.push_back(l);
	ans.push_back(r);
	return ans;
}

-------Inplace merge of two sorted vector

void Solution::merge(vector<int> &A, vector<int> &B)
{
    
    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place
    
    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B
    
    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B
    
    A.resize(A.size() + B.size());
    
    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }
    
}

-------Longest commmon prefix in array
string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size()==1){
        return A[0];
    }
    int n=A.size();
    string ans;
    int i=0;
    int n1=A[0].size(),n2=A[1].size();
    while(i<n1&&i<n2){
        if(A[0][i]==A[1][i]){
            ans.push_back(A[0][i]);
        }else{
            break;
        }
        i++;
    }
    i=2;
    while(i<n){
        string temp=ans;
        ans.clear();
        int j=0;
        int l1=A[i].size();
        int l2=temp.size();
        while(j<l1&&j<l2){
            if(temp[j]==A[i][j]){
                ans.push_back(temp[j]);
            }else{
                break;
            }
            j++;
        }
        i++;
    }
    return ans;
}

-------Roman char to int
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            // Does lesser value precede higher value ? 
            if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
                num -= romanCharToInt(s[i]);
            } else {
                num += romanCharToInt(s[i]);
            }
        }
        return num;
    }

    int romanCharToInt(char c) {
        switch (c) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }
};


--------median search in 2d

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int lo = INT_MAX, hi = INT_MIN;
    for(int i=0; i<n; i++) {
        lo = min(lo, A[i][0]);
        hi = max(hi, A[i][m-1]);
    }
    int mid, res = -1;
    int desiredIndex = (n*m+1)/2;
    int currentIndex;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        
        currentIndex = 0;
        for(int i=0; i<n; i++) {
            currentIndex += lower_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(currentIndex < desiredIndex) {
            lo = mid+1;
            res=mid;
        } else {
            hi = mid-1;
        }
    }
    return res;
}

-----Fraction
string Solution::fractionToDecimal(int A, int B) {
    string ans;
    unordered_map<long long int,int> mp;
    long long int a=(long long int)A;
    long long int b=(long long int)B;
    if(a*b<0){
        ans+="-";
    }
    a=abs(a);
    b=abs(b);
    ans+=to_string(a/b);
    long long int rem=a%b;
    if(rem!=0){
        ans.push_back('.');
    }
    int ind=ans.size();
    while(rem!=0){
        if(mp.find(rem)!=mp.end()){
            ans.insert(mp[rem],"(");
            ans.push_back(')');
            break;
        }
        mp[rem]=ind++;
        rem*=10;
        long long int temp=rem/b;
        ans+=to_string(temp);
        rem=rem%b;
    }
    return ans;
}


------------Points on the straight line
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    unordered_map<double,int>mp;
    if(A.size()<3){
        return A.size();
    }
    int n=A.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        mp.clear();
        int overlap=1;
        int curr_max=0;
        int horz=1;
        for(int j=i+1;j<n;j++){
            double sl;
            if(A[i]==A[j]&&B[i]==B[j]){
                overlap++;
                continue;
            }
            else if(A[j]==A[i]){
                horz++;
            }else{
               sl=(double)(B[j]-B[i])/(double)(A[j]-A[i]);
               mp[sl]++;
            }
            if(mp[sl]>curr_max){
                curr_max=mp[sl];
            }
        }
        ans=max(ans,max(curr_max+overlap,horz));
    }
    return ans;
}

----------N max pair combination
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	priority_queue<pair<int, pair<int, int> > > hp;
	set<pair<int, int> > S;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
	S.insert(make_pair(n-1, n-1));

	vector<int> ans;
	int k=n;
	while(k--){
		pair<int, pair<int, int> > top = hp.top();
		hp.pop();
		ans.push_back(top.first);
		int L = top.second.first;
		int R = top.second.second;
		
		if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() ){
			hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
			S.insert(make_pair(L,R-1));
		}
		if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end()){
			hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
			S.insert(make_pair(L-1, R));
		}
	}
	return ans;
}

--------Min cost tickets

class Solution {
public:
   int mincostTickets(vector<int>& days, vector<int>& costs) {
  unordered_set<int> travel(begin(days), end(days));
  int dp[366] = {};
       int n = days.size();
  for (int i = 1; i <= days[n-1]; ++i) {
    if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
    else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
      cout<<i<<" "<<dp[i]<<endl;
  }
  return dp[days[n-1]];
}
};

-----------Count distinct subsequences
public int numDistinct(String S, String T) {
    // array creation
    int[][] mem = new int[T.length()+1][S.length()+1];

    // filling the first row: with 1s
    for(int j=0; j<=S.length(); j++) {
        mem[0][j] = 1;
    }
    
    // the first column is 0 by default in every other rows but the first, which we need.
    
    for(int i=0; i<T.length(); i++) {
        for(int j=0; j<S.length(); j++) {
            if(T.charAt(i) == S.charAt(j)) {
                mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
            } else {
                mem[i+1][j+1] = mem[i+1][j];
            }
        }
    }
    
    return mem[T.length()][S.length()];
}

----------Max product subarray
int Solution::maxProduct(const vector<int> &A) {
    int mx=1,mn=1;
    int ans=INT_MIN;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]<0){
            int temp=mx;
            mx=mn*A[i];
            mn=temp*A[i];
        }else{
            mn=mn*A[i];
            mx=max(A[i],mx*A[i]);
        }
        ans=max({mx,mn,ans});
        if(mx==0){
            mx=1,mn=1;
        }
    }
    return ans;
}
