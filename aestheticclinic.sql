-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 25, 2021 at 01:53 PM
-- Server version: 10.4.18-MariaDB
-- PHP Version: 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `aestheticclinic`
--
CREATE DATABASE IF NOT EXISTS `aestheticclinic` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin;
USE `aestheticclinic`;

-- --------------------------------------------------------

--
-- Table structure for table `appoinment`
--

DROP TABLE IF EXISTS `appoinment`;
CREATE TABLE `appoinment` (
  `AppoinmentID` int(5) NOT NULL,
  `AppoinmentDate` date NOT NULL,
  `TreatmentType` varchar(255) COLLATE utf8mb4_bin NOT NULL,
  `PatientID` int(5) NOT NULL,
  `DermaID` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

-- --------------------------------------------------------

--
-- Table structure for table `dermatologist`
--

DROP TABLE IF EXISTS `dermatologist`;
CREATE TABLE `dermatologist` (
  `DermaID` int(5) NOT NULL,
  `DermaName` varchar(100) COLLATE utf8mb4_bin NOT NULL,
  `DermaPassword` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `DermaPhoneNumber` varchar(11) COLLATE utf8mb4_bin NOT NULL,
  `DermaDOB` date NOT NULL,
  `DermaAddress` varchar(255) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `dermatologist`
--

INSERT INTO `dermatologist` (`DermaID`, `DermaName`, `DermaPassword`, `DermaPhoneNumber`, `DermaDOB`, `DermaAddress`) VALUES
(3745, 'JESSIE A/K JOHNNY ', 'jessie123', '0105587110', '1974-06-02', '174, JALAN SIPUTANG 3, KG BELAHAN, 00100 SARIKEI SARAWAK ');

-- --------------------------------------------------------

--
-- Table structure for table `patient`
--

DROP TABLE IF EXISTS `patient`;
CREATE TABLE `patient` (
  `PatientID` int(5) NOT NULL,
  `PatientName` varchar(100) COLLATE utf8mb4_bin NOT NULL,
  `PatientPhoneNumber` varchar(11) COLLATE utf8mb4_bin NOT NULL,
  `PatientAddress` varchar(255) COLLATE utf8mb4_bin NOT NULL,
  `PatientPassword` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `PatientDOB` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `patient`
--

INSERT INTO `patient` (`PatientID`, `PatientName`, `PatientPhoneNumber`, `PatientAddress`, `PatientPassword`, `PatientDOB`) VALUES
(86374, 'NURSYAFIQAH ADILLA BINTI MOHD SYAFIQ JACKSON', '0189510801', 'NO 61 HALA KLEBANG RESTU 20, MEDAN KLEBANG RESTU , CHEMOR PERAK', 'ABC1234', '1999-01-29');

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

DROP TABLE IF EXISTS `payment`;
CREATE TABLE `payment` (
  `PaymentID` int(5) NOT NULL,
  `PatientID` int(5) NOT NULL,
  `TreatmentID` int(5) NOT NULL,
  `TreatmentCost` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`PaymentID`, `PatientID`, `TreatmentID`, `TreatmentCost`) VALUES
(1, 86374, 1, 650);

-- --------------------------------------------------------

--
-- Table structure for table `treatment`
--

DROP TABLE IF EXISTS `treatment`;
CREATE TABLE `treatment` (
  `TreatmentID` int(5) NOT NULL,
  `TreatmentCost` int(255) NOT NULL,
  `TreatmentType` varchar(255) COLLATE utf8mb4_bin NOT NULL,
  `DermaID` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `treatment`
--

INSERT INTO `treatment` (`TreatmentID`, `TreatmentCost`, `TreatmentType`, `DermaID`) VALUES
(1, 650, 'SKIN REJENUVATION', 3745);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `appoinment`
--
ALTER TABLE `appoinment`
  ADD PRIMARY KEY (`AppoinmentID`),
  ADD KEY `appoinment_patient_FK` (`PatientID`),
  ADD KEY `appoinment_dermatologist_FK` (`DermaID`),
  ADD KEY `TreatmentType` (`TreatmentType`),
  ADD KEY `TreatmentType_2` (`TreatmentType`);

--
-- Indexes for table `dermatologist`
--
ALTER TABLE `dermatologist`
  ADD PRIMARY KEY (`DermaID`),
  ADD UNIQUE KEY `DermaPassword` (`DermaPassword`);

--
-- Indexes for table `patient`
--
ALTER TABLE `patient`
  ADD PRIMARY KEY (`PatientID`),
  ADD UNIQUE KEY `PatientPassword` (`PatientPassword`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`PaymentID`),
  ADD KEY `payment_patient_FK` (`PatientID`),
  ADD KEY `payment_dermatologist_FK` (`TreatmentID`);

--
-- Indexes for table `treatment`
--
ALTER TABLE `treatment`
  ADD PRIMARY KEY (`TreatmentID`),
  ADD KEY `Treatment_Dermatologist_FK` (`DermaID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `appoinment`
--
ALTER TABLE `appoinment`
  MODIFY `AppoinmentID` int(5) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `payment`
--
ALTER TABLE `payment`
  MODIFY `PaymentID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `treatment`
--
ALTER TABLE `treatment`
  MODIFY `TreatmentID` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `appoinment`
--
ALTER TABLE `appoinment`
  ADD CONSTRAINT `appoinment_dermatologist_FK` FOREIGN KEY (`DermaID`) REFERENCES `dermatologist` (`DermaID`),
  ADD CONSTRAINT `appoinment_patient_FK` FOREIGN KEY (`PatientID`) REFERENCES `patient` (`PatientID`);

--
-- Constraints for table `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `payment_dermatologist_FK` FOREIGN KEY (`TreatmentID`) REFERENCES `treatment` (`TreatmentID`),
  ADD CONSTRAINT `payment_patient_FK` FOREIGN KEY (`PatientID`) REFERENCES `patient` (`PatientID`);

--
-- Constraints for table `treatment`
--
ALTER TABLE `treatment`
  ADD CONSTRAINT `Treatment_Dermatologist_FK` FOREIGN KEY (`DermaID`) REFERENCES `dermatologist` (`DermaID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
