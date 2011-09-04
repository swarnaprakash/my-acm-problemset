def number(n)
  return 1 if n == 0
  return 2 * number(n/2) + 1
end

gets.to_i.times do
  puts number(gets.to_i)
end
