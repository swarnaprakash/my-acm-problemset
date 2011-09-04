class Coin
  attr_accessor :weight, :value
end

def solve(net_weight, coins_arr)
  # Sort the coins in descending order of the ratio weight/value
  coins_arr.sort! do |a,b|
    a.value * b.weight - a.weight * b.value
  end

  # Traverse from largest ratio to smallest ratio.
  # Pick a coin as many times as possible.
  ans = 0
  coins_arr.each do |coin|
    while net_weight >= coin.weight
      net_weight -= coin.weight
      ans += coin.value
    end
  end

  if net_weight == 0
    return ans
  else
    return 'Impossible'
  end
end

gets.to_i.times do
  ef_parts = gets.split
  w = ef_parts[1].to_i - ef_parts[0].to_i
  coins = []
  gets.to_i.times do
    coin_parts = gets.split
    coin = Coin.new
    coin.value = coin_parts[0].to_i
    coin.weight = coin_parts[1].to_i
    coins << coin
  end
  puts solve(w,coins)
end
