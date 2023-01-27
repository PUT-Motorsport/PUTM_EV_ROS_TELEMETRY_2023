// Auto-generated. Do not edit!

// (in-package ROS_Telemetry.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Apps_main {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pedal_position = null;
      this.counter = null;
      this.position_diff = null;
      this.device_state = null;
    }
    else {
      if (initObj.hasOwnProperty('pedal_position')) {
        this.pedal_position = initObj.pedal_position
      }
      else {
        this.pedal_position = 0;
      }
      if (initObj.hasOwnProperty('counter')) {
        this.counter = initObj.counter
      }
      else {
        this.counter = 0;
      }
      if (initObj.hasOwnProperty('position_diff')) {
        this.position_diff = initObj.position_diff
      }
      else {
        this.position_diff = 0;
      }
      if (initObj.hasOwnProperty('device_state')) {
        this.device_state = initObj.device_state
      }
      else {
        this.device_state = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Apps_main
    // Serialize message field [pedal_position]
    bufferOffset = _serializer.uint16(obj.pedal_position, buffer, bufferOffset);
    // Serialize message field [counter]
    bufferOffset = _serializer.uint8(obj.counter, buffer, bufferOffset);
    // Serialize message field [position_diff]
    bufferOffset = _serializer.int8(obj.position_diff, buffer, bufferOffset);
    // Serialize message field [device_state]
    bufferOffset = _serializer.uint8(obj.device_state, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Apps_main
    let len;
    let data = new Apps_main(null);
    // Deserialize message field [pedal_position]
    data.pedal_position = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [counter]
    data.counter = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [position_diff]
    data.position_diff = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [device_state]
    data.device_state = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ROS_Telemetry/Apps_main';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4a5de748b20de5195675b828a1b04fa1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint16 pedal_position
    uint8 counter
    int8 position_diff
    uint8 device_state
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Apps_main(null);
    if (msg.pedal_position !== undefined) {
      resolved.pedal_position = msg.pedal_position;
    }
    else {
      resolved.pedal_position = 0
    }

    if (msg.counter !== undefined) {
      resolved.counter = msg.counter;
    }
    else {
      resolved.counter = 0
    }

    if (msg.position_diff !== undefined) {
      resolved.position_diff = msg.position_diff;
    }
    else {
      resolved.position_diff = 0
    }

    if (msg.device_state !== undefined) {
      resolved.device_state = msg.device_state;
    }
    else {
      resolved.device_state = 0
    }

    return resolved;
    }
};

module.exports = Apps_main;
