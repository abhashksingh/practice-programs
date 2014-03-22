/*again not my code if this works.I will code it again in C++ after understanding it*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Solution {

    int[] lSmaller, rLarger, treeArray, dscArray, lFlags, rFlags;

    int size, count = 0;

    Solution(int aSize, int[] inputArray) {
        size = aSize;
        lSmaller = new int[size];
        rLarger = new int[size];
        dscArray = new int[size];
        int[] tmpArray = Arrays.copyOf(inputArray, inputArray.length);
        Arrays.sort(tmpArray);
        HashMap<Integer, Integer> tmpMap = new HashMap<Integer, Integer>(size);
        for (int i = 0; i < size; i++) {
            if (!tmpMap.containsKey(tmpArray[i])) {
                count++;
                tmpMap.put(tmpArray[i], count);
            }
        }
        count++;
        treeArray = new int[count];
        lFlags = new int[count];
        rFlags = new int[count];
        for (int i = 0; i < size; i++) {
            dscArray[i] = tmpMap.get(inputArray[i]);
        }

    }

    void update(int idx) {
        while (idx < count) {
            treeArray[idx]++;

            idx += (idx & -idx);
        }
    }

    int read(int index) {
        int sum = 0;
        while (index > 0) {
            sum += treeArray[index];
            index -= (index & -index);
        }
        return sum;
    }

    void countLeftSmaller() {
        Arrays.fill(treeArray, 0);
        Arrays.fill(lSmaller, 0);
        Arrays.fill(lFlags, 0);
        for (int i = 0; i < size; i++) {
            int val = dscArray[i];
            lSmaller[i] = read(val - 1);
            if (lFlags[val] == 0) {
                update(val);
                lFlags[val] = i + 1;
            } else {
                lSmaller[i] -= lSmaller[lFlags[val] - 1];
            }
        }
    }

    void countRightLarger() {

        Arrays.fill(treeArray, 0);
        Arrays.fill(rLarger, 0);
        Arrays.fill(rFlags, 0);
        for (int i = size - 1; i >= 0; i--) {
            int val = dscArray[i];
            rLarger[i] = read(count - 1) - read(val);
            if (rFlags[val] == 0) {
                update(val);
                rFlags[val] = i + 1;
            }
        }
    }

    long countTriplets() {
        long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += lSmaller[i] * rLarger[i];
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] a = new int[N];
        String[] strs = br.readLine().split(" ");
        for (int i = 0; i < N; i++)
            a[i] = Integer.parseInt(strs[i]);
        Solution sol = new Solution(N, a);
        sol.countLeftSmaller();
        sol.countRightLarger();
        System.out.println(sol.countTriplets());
    }
}
