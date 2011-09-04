$c

def my_power(a,n)
#  puts "#{a},#{n}"
  $c += 1
  return 1 if n == 0
  return my_power(a,n/2) * my_power(a,n/2) if n%2 == 0
  return a * my_power(a,n/2) * my_power(a,n/2)
end

0.upto(50) do |x|
  $c = 0
#  puts "x=#{x}"
  my_power(1,x)
  puts $c
end
