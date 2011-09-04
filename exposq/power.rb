def my_power(a,n)
  return 1 if n == 0
  return my_power(a,n/2) * my_power(a,n/2) if n%2 == 0
  return a * my_power(a,n/2) * my_power(a,n/2)
end
