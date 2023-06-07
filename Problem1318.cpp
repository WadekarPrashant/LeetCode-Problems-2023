    public int minFlips(int a, int b, int c) {

        int flips = 0;

        while(a > 0 || b > 0 || c > 0) {
            int ca = c % 2;
            c/=2;


            int ba = b%2;
            b/=2;
            int aa = a%2;
            a/=2;
            if (ca == 0) {
                if (ba ==1) flips++;
                if (aa ==1) flips++;
            } else {
                if (ba == 0 && aa == 0) flips++;
            }
        }
        return flips;
        
    }
