const std = @import("std");
const io = std.io;
const fmt = std.fmt;

pub fn main() !void {
    const stdin = io.getStdIn();
    const stdout = std.io.getStdOut().writer();

    while (true) {
        // Read the first integer
        try stdout.print("First number: ", .{});
        var line_buf: [20]u8 = undefined;
        const amt = try stdin.read(&line_buf);
        const line = std.mem.trimRight(u8, line_buf[0..amt], "\r\n");
        const num1 = fmt.parseUnsigned(u8, line, 10) catch {
            try stdout.print("Error reading number\n", .{});
            continue;
        };

        // Read the operator
        // Read the first integer
        try stdout.print("Operator: ", .{});
        var line_buf_opp: [20]u8 = undefined;
        const amt_opp = try stdin.read(&line_buf_opp);
        _ = amt_opp;
        const operator = line_buf_opp[0];

        // Read the second integer
        // Read the first integer
        try stdout.print("Second number: ", .{});
        var line_buf2: [20]u8 = undefined;
        const amt2 = try stdin.read(&line_buf2);
        const line2 = std.mem.trimRight(u8, line_buf2[0..amt2], "\r\n");
        const num2 = fmt.parseUnsigned(u8, line2, 10) catch {
            try stdout.print("Error reading number\n", .{});
            continue;
        };

        // Perform the calculation based on the operator
        var result: i32 = switch (operator) {
            '+' => num1 + num2,
            '-' => num1 - num2,
            '*' => num1 * num2,
            '/' => num1 / num2,
            else => 0,
        };

        // Print the result
        try stdout.print("\n{} {?c} {} = {}\n", .{ num1, operator, num2, result });
    }

    return void{};
}
