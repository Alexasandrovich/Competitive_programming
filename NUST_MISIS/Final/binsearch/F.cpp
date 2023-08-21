#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct BallManData
{
  int T = 0; // time
  int Z = 0; // ball limit with rest
  int Y = 0; // rest

  int ballCount = 0;
  int finalBallCount = 0;
};

bool checkValid(const vector<BallManData>& ballMansData)
{ 
  int res = 0;  
  for(const auto& ballManData : ballMansData)  
  {
    res += ballManData.finalBallCount;  
  }
  return res > 0;
}

bool check(int t, int m, vector<BallManData>& ballMansData)
{
  int cnt = 0;  
  for(auto& ballManData: ballMansData)
  {
    int ballCountNoRest = (t / (ballManData.T * ballManData.Z + ballManData.Y)) * ballManData.Z;
    int ballCountByTime = min((t % (ballManData.T * ballManData.Z + ballManData.Y) / ballManData.T), ballManData.Z);
    cnt += ballCountByTime + ballCountNoRest;
    ballManData.ballCount = ballCountByTime + ballCountNoRest;
  }

  if(cnt == m)
  {
    for(auto& ballManData : ballMansData)
    {
      ballManData.finalBallCount = ballManData.ballCount;
    }
  }

  return cnt >= m;
}

void repair(int m, vector<BallManData>& ballMansData, int time)
{
  int enough = 0;
  for(auto& ballManData : ballMansData)  
  {
    int balls = ballManData.Z * time;  
    ballManData.finalBallCount = balls;
    enough += balls;
    if(enough >= m) break;
  }
}

int getBallCount(int m, vector<BallManData>& ballMansData)
{
  int left = -1;
  int right = 10000000;
  while(right - left > 1)
  {
    int t = (left + right) / 2;
    if(check(t, m, ballMansData))
    {
      right = t;  
    }else left = t;
  }
  if(!checkValid(ballMansData))
  {
    repair(m, ballMansData, right);
  }
  return right;
}

int main()
{
  int N, M;
  cin >> M >> N;
  vector<BallManData> ballMansData(N);

  for(size_t i = 0; i < N; i++)
  {
    cin >> ballMansData[i].T >> ballMansData[i].Z >> ballMansData[i].Y;
  }
  cout << getBallCount(M, ballMansData) << endl;


  for(const auto& ballManData : ballMansData)
  {
    cout << ballManData.finalBallCount <<  " ";
  }
  return 0;
}
