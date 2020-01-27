require 'pp'
require 'prime'
require 'set'


N=gets.chomp.split(' ').map{|n| n}.first

keta = N.chars.size

ans = 0;
now_keta =1;
N.chars[0..-2].map(&:to_i).reverse.each do |n|
  puts 9**(keta -2)
  puts n*(9**(keta -2))
  ans= ans + (n*9**(keta -2))

  ans = ans+ n*now_keta
  keta-=1
  now_keta+=1
end

if N.to_i.odd?
  puts 0
else
  puts ans
end
