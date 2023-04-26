public static class Team 
{

    public int num;
    public int win;
    public int lose;
    public int score;
    public Team(int num) 
    {
      this.num = num;
      this.win = 0;
      this.lose = 0;
      this.score = 0;
    }
}

  public static void fun() {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      if (n == 0 && m == 0) {
        return;
      }
      Team[] team = new Team[n];
      for (int i = 0; i < n; i++) {
        team[i] = new Team(i);
      }
      for (int i = 0; i < m; i++) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        a--;
        b--;
        if (c == 1) {
          team[a].win++;
          team[a].score += 3;
          team[b].lose++;
          team[b].score -= 1;
        } else if (c == -1) {
          team[b].win++;
          team[b].score += 3;
          team[a].lose++;
          team[a].score -= 1;
        } else {
          team[a].score++;
          team[b].score++;
        }
      }

      Arrays.sort(team, new Comparator<Team>() {
        @Override
        public int compare(Team o1, Team o2) {
          if (o1.score != o2.score) {
            return o2.score - o1.score;
          } else if (o1.win != o2.win) {
            return o2.win - o1.win;
          } else if (o1.lose != o2.lose) {
            return o1.lose - o2.lose;
          } else {
            return o1.num - o2.num;
          }
        }
      });

      for (int i = 0; i < n; i++) {
        System.out.print(team[i].num + 1);
        if (i != n - 1) {
          System.out.print(" ");
        }
      }
      System.out.println();
    }
  }