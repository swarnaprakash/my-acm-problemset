# Author: Swarnaprakash

def big_print(p,q,len)
  len.times do
    print (rand(q) < p) ? 0 : 1
  end
  puts
end

n = 20000

2.upto(6) do |q|
  f = []
  1.upto(q-1) do |p|
    f << Rational(p,q)
  end
  f.uniq!
  f.each_index do |i|
    i.upto(f.size - 1) do |j|
      big_print(f[i].numerator,f[i].denominator,n)
      big_print(f[j].numerator,f[j].denominator,n)
    end
  end
end
