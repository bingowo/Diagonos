class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] nums = new int[1001];//arr1.length, arr2.length <= 1000
        int[] res = new int[arr1.length];
        for(int i : arr1 ) nums[i] ++;//记录arr1中数字出现的次数
        int index = 0 ;
        for ( int j : arr2 ) {//对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同
            while ( nums[j] > 0){
                res[index++] = j;
                nums[j]--;
            }
        }
        for ( int k = 0 ;k < nums.length ;k++) {//处理arr2未出现的数字
            while ( nums[k] > 0){
                res[index++] = k;
                nums[k]--;
            }
        }
        return res;
    }
}
