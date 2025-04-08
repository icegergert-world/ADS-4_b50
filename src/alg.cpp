// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int rig, lef;
  int stop = len - 1;
  while (stop > 0 && arr[stop] > value) {
    stop--;
  }
  for (lef = 0; lef < len; lef++) {
    for (rig = stop; rig > lef; rig--) {
      if (arr[lef] + arr[rig] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int x = value - arr[i];
    int lef = i + 1;
    int rig = len - 1;
    while (lef <= rig) {
      int cen = lef + (rig - lef) / 2;
      if (arr[cen] == x) {
        count++;
        int j = cen - 1;
        while (j >= lef && arr[j] == x) {
          count++;
          j--;
        }
        j = cen + 1;
        while (j <= rig && arr[j] == x) {
          count++;
          j++;
        }
        break;
      } else if (arr[cen] < x) {
        lef = cen + 1;
      } else {
        rig = cen - 1;
      }
    }
  }
  return count;
}
