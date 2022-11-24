public class kid {
    static long answer =0;
    public static void mergeSort(int[] a , int i ,int j){
        if (i<j){
            int mid =(i+j)/2;
            mergeSort(a, i, mid);
            mergeSort(a, mid+1, j);
            merge(a, i, mid, j);
        }
    }
    static void merge(int arr[], int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
        int i = 0, j = 0; 
        int k = l; 
        
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
                answer += n1-i;
            } 
            k++; 
        } 
  
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    public static void main(String[] args){
        Kattio io = new Kattio(System.in);
        String n = io.getWord();
        int[] m = new int[n.length()];
        int idx =0;
        while (idx<n.length()){
            m[idx] = n.charAt(idx);
            idx++;
        }
        mergeSort(m, 0,n.length()-1);
        io.println(answer);
        io.close();
    }
}

