require 'csv'
require 'pp'

arr = []

CSV.foreach('../data', :col_sep => "\t") do |row|
  next if row.size == 0
  next if row[1] == "0"
  arr << row
end

arr.sort_by! {|item| - (item[1].to_i) }

10.times do |i|
  pp arr[i]
end
