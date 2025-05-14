// Thêm vào utils/dateUtils.js
export const formatDateTime = (dateStr, timeStr) => {
  if (!dateStr) return '';
  
  // Xử lý cả 2 định dạng date: dd/mm/yyyy và yyyy-mm-dd
  const [day, month, year] = dateStr.includes('/') 
    ? dateStr.split('/')
    : dateStr.split('-').reverse();
  
  const formattedDate = `${day.padStart(2, '0')}/${month.padStart(2, '0')}/${year}`;
  
  if (!timeStr) return formattedDate;
  return `${formattedDate} ⏰ ${timeStr}`;
};