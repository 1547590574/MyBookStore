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

 Date: 08/09/2019 16:28:23
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book`  (
  `ibsn` varchar(30) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  `book_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `author` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  `publisher` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `dicount` decimal(3, 2) NULL DEFAULT NULL,
  `count` varchar(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`ibsn`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of book
-- ----------------------------
INSERT INTO `book` VALUES ('19990701', '格林童话', '马克', 120.00, '外国教育出版社', 0.85, '-40');
INSERT INTO `book` VALUES ('19990901', '百万英镑', '香克斯', 66.00, '中国数学出版社', 0.95, '60');
INSERT INTO `book` VALUES ('19991001', '海贼王', '尾田荣一郎', 100.00, '中国漫画出版社', 0.90, '7');
INSERT INTO `book` VALUES ('19991101', '火影忍者', '疾风传', 99.00, '中国漫画出版社', 0.70, '97');
INSERT INTO `book` VALUES ('20000001', '盗墓笔记3', '南派三叔', 20.00, '中国漫画出版社', 1.00, '97');
INSERT INTO `book` VALUES ('20000002', '盗墓笔记2', '南派三叔', 100.00, '小胖出版社', 0.80, '100');
INSERT INTO `book` VALUES ('20000003', '盗墓笔记1', '南派三叔', 20.00, '中国盗墓出版社', 1.00, '99');

SET FOREIGN_KEY_CHECKS = 1;
