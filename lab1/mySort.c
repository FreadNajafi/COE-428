void mySort(int d[], unsigned int n)
{
	int j,element;
	for (int i = 0; i < n; i++){
		j = i - 1;
		element = d[i];
		while (j >= 0 && d[j] > element){
		d[j+1] = d[j];
		j--;
}
		d[j + 1] = element;
}
}
		
		
