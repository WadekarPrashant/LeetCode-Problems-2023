class SnapshotArray {

    record P(int snap, int val){}

    List<P>[] snap;
    int snapID = -1;
    public SnapshotArray(int length) {
        snap = new ArrayList[length];
        for (int i =0; i < length; i++) {
            snap[i] = new ArrayList<>();
        }
    }
    
    public void set(int index, int val) {
        var cur = snap[index];

        if (!cur.isEmpty() && cur.get(cur.size()-1).snap == snapID) {
            cur.remove(cur.size()-1);
        }
        cur.add(new P(snapID, val));
    }
    
    public int snap() {
        
        return ++snapID;
    }
    
    public int get(int index, int snap_id) {
        var cur = snap[index];
        if (cur.isEmpty()) return 0;
        int i = cur.size()-1;
        while(cur.get(i).snap >= snap_id) {
            i--;
            if (i < 0) return 0;
        }
        return cur.get(i).val;
    }
}
