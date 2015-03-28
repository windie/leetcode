void rec(vector<int> & a, int begin, int end){
	if(begin>=end){
		return;
	}
	int pivot = a[begin];
	int i = begin, j = end;
	while(i < j){
		while(i < j && pivot <= a[j]){
			j--;
		}
		if(i < j){
			a[i] = a[j]
		}
		while(i < j && a[i] <= pivot){
			i++;
		}
		if(i < j){
			a[j] = a[i];
		}
	}
	a[i] = pivot;
	rec(a, begin, i-1);
	rec(a, i+1, end);
}

void qsort(vector<int> & a){
	rec(a, 0, a.size()-1);
}