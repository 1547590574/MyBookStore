/*
 Navicat MySQL Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 80016
 Source Host           : localhost:3306
 Source Schema         : mysql

 Target Server Type    : MySQL
 Target Server Version : 80016
 File Encoding         : 65001

 Date: 08/09/2019 16:28:28
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bookorder
-- ----------------------------
DROP TABLE IF EXISTS `bookorder`;
CREATE TABLE `bookorder`  (
  `username` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `ibsn` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `time` datetime(0) NOT NULL,
  `number` int(10) NOT NULL,
  `situation` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`ibsn`, `username`, `situation`, `time`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of bookorder
-- ----------------------------
INSERT INTO `bookorder` VALUES ('123456', '19990601', '2019-05-01 23:03:01', 8, '0');
INSERT INTO `bookorder` VALUES ('123456', '19990601', '2019-09-08 15:52:47', 5, '0');
INSERT INTO `bookorder` VALUES ('123456', '19990601', '2019-09-08 15:52:22', 2, '3');
INSERT INTO `bookorder` VALUES ('123456', '19990701', '2019-09-06 01:57:43', 4, '0');
INSERT INTO `bookorder` VALUES ('123456', '19990701', '2017-06-13 23:04:15', 6, '1');
INSERT INTO `bookorder` VALUES ('123456', '19990701', '2019-07-15 00:51:54', 3, '3');
INSERT INTO `bookorder` VALUES ('123456', '19990801', '2019-07-24 15:56:28', 2, '3');
INSERT INTO `bookorder` VALUES ('123456', '19991001', '2019-09-06 11:20:58', 3, '0');
INSERT INTO `bookorder` VALUES ('123456', '19991001', '2019-09-02 15:56:32', 2, '1');
INSERT INTO `bookorder` VALUES ('123456', '19991101', '2019-09-06 15:46:34', 3, '3');
INSERT INTO `bookorder` VALUES ('123456', '20000003', '2019-09-06 15:30:40', 1, '0');
INSERT INTO `bookorder` VALUES ('123456', '20000005', '2019-09-06 15:23:46', 2, '3');

SET FOREIGN_KEY_CHECKS = 1;
