v.erase(remove(v.begin(), v.end(), val), v.end());

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
