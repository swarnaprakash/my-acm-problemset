0.upto(50) do |x|
  puts x
end

def my_rand(y)
  x = y/10
  return rand(y-x) + x
end

m = 10 ** 15
n = m
149.times do
  puts my_rand(n)
  if n == 1000
    n = m
  else
    n /= 10
  end
end


