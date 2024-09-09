//
//  main.swift
//  array-swift
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

import Foundation

@inlinable public func xassert(_ cond: Bool) { if !cond { print("assert failure"); exit(-1) } }

func arrayTest(_ count: Int) {
    var buffer: [Int] = []
    xassert(buffer.count == 0)
    for i in 0..<count {
        buffer.append(i)
    }
    xassert(buffer.count == count)
    for i in 0..<buffer.count {
        xassert(buffer[i] == i)
    }
    buffer = []
    xassert(buffer.count == 0)
}

func arrayForcedOptionalTest(_ count: Int) {
    var buffer: [Int]?
    xassert(buffer?.count == nil)
    buffer = []
    for i in 0..<count {
        buffer!.append(i)
    }
    xassert(buffer!.count == count)
    for i in 0..<buffer!.count {
        xassert(buffer![i] == i)
    }
    buffer = nil
    xassert(buffer?.count == nil)
}

func arrayUnforcedOptionalTest(_ count: Int) {
    var buffer: [Int]?
    xassert(buffer?.count == nil)
    buffer = []
    for i in 0..<count {
        buffer?.append(i)
    }
    
    guard let rawBuffer = buffer else { fatalError() }
    for i in 0..<rawBuffer.count {
        xassert(rawBuffer[i] == i)
    }
    xassert(rawBuffer.count == count)
    buffer = nil
    xassert(buffer?.count == nil)
}

func performTest(_ pass: Int, _ test: (Int) -> Void) {
    print("\(pass) [starting] steps=\(steps)")
    let startTime = Date()
    test(steps)
    let duration = Float(startTime.timeIntervalSinceNow * -1000.0)
    let formatter = NumberFormatter()
    formatter.maximumFractionDigits = 3
    let durationText = formatter.string(for: duration) ?? ""
    print("\(pass) [done] time=\(durationText)ms\n")
}

struct TestType: Sendable {
    static let nonOptional = TestType(title: "non-optional", test: arrayTest)
    static let forcedOptional = TestType(title: "forced optional", test: arrayForcedOptionalTest)
    static let unforcedOptional = TestType(title: "unforced optional", test: arrayUnforcedOptionalTest)

    let title: String
    let test: @Sendable (Int) -> Void
}

let steps = 1000000
let passes = 2

let testType: TestType = if CommandLine.argc == 2 {
  switch Int(CommandLine.arguments[1]) {
  case 1:
      .forcedOptional
  case 2:
      .unforcedOptional
  default:
      .nonOptional
  }
} else {
    .nonOptional
}

print("Swift \(testType.title)")
for i in 0..<passes {
    performTest(i, testType.test)
}
