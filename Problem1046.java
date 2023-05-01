class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        for (int n : stones) {
            q.offer(n);
        }

        while (q.size() > 1) {
            int st = q.poll();
            int nd = q.poll();

            if (st > nd) {
                q.offer(st - nd);
            }
        }

        if (q.isEmpty()) {
            return 0;
        }

        return q.peek();
    }
}
