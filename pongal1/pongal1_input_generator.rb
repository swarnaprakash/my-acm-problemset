# Author: Swarnaprakash

def print_binary(x,len)
  (len-1).downto(0) do |i|
    print x[i]
  end
  puts
end

def big_print(p,q,len)
  len.times do
    print (rand(q) < p) ? 0 : 1
  end
  puts
end

1.upto(6) do |n|
  arr = []
  (n+1).times do
    arr << rand(1<<n)
  end
  arr.each_index do |i|
    (i+1).upto(arr.size - 1) do |j|
      print_binary(arr[i],n)
      print_binary(arr[j],n)
    end
  end
end

(1.step(10,1).to_a + 10.step(100,20).to_a + 200.step(1000,200).to_a).each do |n|
  big_print(1,2,n)
  big_print(1,2,n)

  big_print(1,3,n)
  big_print(2,3,n)

  big_print(2,3,n)
  big_print(2,3,n)

  big_print(1,5,n)
  big_print(4,5,n)

  big_print(2,5,n)
  big_print(3,5,n)

  big_print(1,5,n)
  big_print(3,5,n)
  
  big_print(4,5,n)
  big_print(4,5,n)
end

big_print(0,5,1000)
big_print(5,5,1000)
